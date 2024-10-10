/*busstop.cpp*/

//
// A bus stop in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//

#include <iostream>
#include <map>

#include "busstop.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

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

//
// print a bus stop prediction
//
void BusStop::printBusPredictions(string response) {
    auto jsondata = json::parse(response);
    auto bus_response = jsondata["bustime-response"];
    auto predictions = bus_response["prd"];

    // for each prediction (a map) in the prediciton list:
    for (auto& M : predictions) {
        cout << "  vehicle #" << stoi(M["vid"]) <<
    }
}