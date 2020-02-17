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
using namespace std;

int main()
{
    int n, k; 
    
    //Briefly explain program and then prompt input from user
    cout << "TSP: Assume a traveling salesperson has 'K' cities to visit to sell widgets. ";
    cout << "The salesperson will start and stop at the same city.\n" <<
            "Assuming the salespereson will stop at 1 address per city, what order of cities gives the shortest" <<
            "total distance(time) for the entire trip?\n" << endl;
    cout << "Enter a value for K(number of cities to be visited):\n";
    cin >> k; //number of cities
    cout << "Enter a value for N(length of square grid):\n";
    cin >> n; //grid length
    
    //[INPUT CHECK]
    //Valid input range: ( 4 <= K <=9 ) and ( 10 <= N <= 30 )
    //check if input for n and k is valid
    //if not valid: re-prompt user for input

    //if valid:
    //random select integer coordinates for each K(cities) 
    //Use text to show user where each city(K) appear on grid. [assign numbers to each city maybe?]
    
    //[CALCUATIONS]
    //Next:
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
