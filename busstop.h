/*busstop.h*/

//
// A bus stop in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//

#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class BusStop
{
public: 
    int ID;
    int Route;
    string StopName;
    string Direction;
    string Location;
    double Lat;
    double Lon;

    //
    // constructor
    //
    BusStop(int id, int route, string stopName, string direction, string location, double lat, double lon);

    //
    // print a bus stop
    //
    void print();

    //
    // print a bus stop prediction
    //
    void printBusPredictions(string response);
};