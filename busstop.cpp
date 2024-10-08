/*busstop.cpp*/

//
// A bus stop in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//

#include "busstop.h"
#include <iostream>

using namespace std;

//
// constructor
//
BusStop::BusStop(int id, int route, string stopName, string direction, string location, double lat, double lon)
: ID(id), Route(route), StopName(stopName), Direction(direction), Location(location), Lat(lat), Lon(lon)
{}

//
// prints a bus stop
//
void BusStop::print() {
    cout << ID << ": bus " << Route << ", " << StopName << ", " << Location << ", " << Direction << ", location (" << Lat << ", " << Lon << ")" << endl;
}