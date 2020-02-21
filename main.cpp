/****************************************************************************************************
/ Program Title    : Analyzing a Random TSP
/ File Name        : main.cpp
/ External Files   : N/A
/ Files Created    : N/A
/ Programmer Names : Samuel Kinsella, Jacob Luciani, Anna Nguyen
/ Email(s)         : skgfd@mail.umsl.edu, jhln87@mail.umsl.edu, anb6d@mail.umsl.edu
/ Course           : CS4500 - 002
/ Date             : 
/ Program Summary  : Program using an algorithm to solve TSP as described in HW3
/ Resources        :
*****************************************************************************************************/

//[C++ or Java ?? I'm okay with either!]

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;

//structure to store city coordinates-data (x,y)
struct CityData {
    int x, y, digit; 
    //digit to present each city (0,1,2,...)
    CityData(int digit_, int x_, int y_)
        : digit(digit_), x(x_), y(y_)
    { }
    
    bool operator <(CityData otherCity) const
    {
        return digit < otherCity.digit;
    }
    
    double distanceFrom(CityData otherCity)
    {
        return sqrt(pow((x - otherCity.x), 2) + pow((y - otherCity.y), 2));
    }
};


void print(vector<CityData> const &cityVector)
{
    for (int i = 0; i < cityVector.size(); i++)
    {
        cout << cityVector[i].digit << " ";
    }
}

void getPermutations(vector<CityData> cityVector)
{
    CityData firstCity = cityVector.front();
    cityVector.erase(cityVector.begin());
    
    do {
        cityVector.insert(cityVector.begin(), firstCity);
        cityVector.push_back(firstCity);
        print(cityVector);
        cityVector.erase(cityVector.begin());
        cityVector.pop_back();
        cout << "\n";
    } while (next_permutation(cityVector.begin(), cityVector.end()));
}

vector<vector<double>> getDistanceMatrix(vector<CityData> cityVector)
{
    int len = cityVector.size();
    
    vector<vector<double>> distanceMatrix(len, vector<double>(0, 0));
    
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            distanceMatrix[i].push_back(cityVector[i].distanceFrom(cityVector[j]));
        }
    }
    
    return distanceMatrix;
}

void printDistanceMatrix(vector<vector<double>> distanceMatrix)
{
    cout.precision(2);
    
    for (int i = 0; i < distanceMatrix.size(); i++)
    {
        for (int j = 0; j < distanceMatrix[i].size(); j++)
        {
            cout << fixed << distanceMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, k, x, y; //coordinates (x,y)
    int row, column; //for grid
    int input_check = 0;
    
    //Briefly explain program and then prompt input from user
    cout << "TSP: Assume a traveling salesperson has 'K' cities to visit to sell widgets. ";
    cout << "The salesperson will start and stop at the same city.\n" <<
            "Assuming the salespereson will stop at 1 address per city, what order of cities give the shortest " <<
            "total distance(time) for the entire trip?\n" << endl;
    
    //[INPUT CHECK]
    do {
        //prompt user
        cout << "Enter a value for K(number of cities to be visited): [Min: 4, Max: 9]\n";
        cin >> k; //number of cities
        
        if (k>=4 && k<=9) {
            //exit while loop if valid
            input_check = input_check + 1;
        } else {
            //Error message for invalid input & reprompt user
            cout << "\nError! Value must be: 4 <= K <=9\n";
        }
    } while (input_check == 0);
    
    input_check = 0;
    
    do {
        //prompt user
        cout << "Enter a value for N(length of square grid): [Min: 10, Max: 30]\n";
        cin >> n; //grid length
        
        //Valid input range: 10 <= N <= 30
        if (n>=10 && n<=30) {
            //exit while loop if valid
            input_check = input_check + 1;
        } else {
            //Error message for invalid input & reprompt user
            cout << "\nError! Values must be: 10 <= N <= 30 \n";
        }
    } while (input_check == 0);

    //if valid:
    cout << "\n[ Starting Information ]";
    cout << "\nTotal number of cities to be visited: " << k << endl;
    cout << "Grid Size: " << n << "x" << n << endl;
    cout << "Each city will now be assigned a number from 0 to " << (k-1) << ".";
            
    srand(time(0)); //seed for rand function
    vector<CityData> arrCity;
    arrCity.reserve(k);
    
    //randomizing coordinates (x,y) for each k(city)
    for(int i=0; i<k; i++) {
        arrCity.emplace_back(i, rand() % n, rand() % n);
    }
    
    //loop to display coordinates for each city
    cout << "\n\nHere are the (x,y) coordinates for each city:\n";
    for(int k=0; k< arrCity.size(); k++) {
        //[k].digit = City(k) , [k].x = x coordinate at [k], [k].y = y coordinate at [k]
        cout << "City " << arrCity[k].digit << ": (" << arrCity[k].x << "," << arrCity[k].y << ")" << endl;
    }    
    
    cout << "\nGrid with city locations:\n";
    //loop to check city location on grid
    for (row=0; row<n; row++) {
        for (column=0; column<n; column++) {
            int w = -1;
            for (int k = 0; k < arrCity.size(); k++) {
                //check where (x,y) match (row, column) for each city[k] to display on grid
                if ((row == arrCity[k].y) && (column == arrCity[k].x)) {
                    w = k;
                }
            }
            
            //display grid with digits representing each city
            if (w>=0) {
                //grid cells containing a city
                cout << "|" << arrCity[w].digit;
            } else {
                //empty grid cells
                cout << "|_";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    getPermutations(arrCity);
    
    vector<vector<double>> distanceMatrix = getDistanceMatrix(arrCity);
    printDistanceMatrix(distanceMatrix);
    
    cout << "\n[NOTE]";
    cout << "\nRows (left to right) starts from 0 to " << (n-1) << endl;
    cout << "Columns (top to bottom) 0 to " << (n-1) << endl;

    //[CALCUATIONS]
    cout << "\n[ Calculating Shortest Route ]\n";
    //Calculate distance from each city to the other cities
    //Print out matrix that includes each of these distances (real numbers displayed w/at least one decimal place)
    //Note: Program should store better precision of these calculations
    //Determine shortest route through cities using brute force technique **Find algorithm online(?)

    //Compare distances and determine shortest route
    //Note: Start with 1st city (City 0 or K(0))
    //Print shortest route found so far as program checcks paths [Maybe use loop?]
    //Include in printout: cities that the path goes through in order and shortest length so far
    //Maybe something like: "Shortest route now; City routes passed:... Time taken for this route: ..." (??)
    
    //[FINAL RESULTS]
    //Final display: "Overall shortest route: ... " (??)
    
    //Program ends.
    return 0;
}
