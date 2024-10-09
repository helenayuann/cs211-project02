/*busstops.cpp*/

//
// A collection of bus stops in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <map>
#include "busstops.h"
#include "busstop.h"
#include "building.h"
#include "buildings.h"
#include "dist.h"

using namespace std;

//
// readBusStops
//
// Given the name of a CSV file, input the data and
// build a container of BusStop objects
//
BusStops::BusStops(string filename)
{
    ifstream infile;

    infile.open(filename);
    if (!infile.good()) {
        return;
    }

    while (!infile.eof()) {
        string line;
        getline(infile, line); // read line from input file

        if (infile.fail()) {
            break;
        }

        stringstream parser(line);

        string id_str, route_str, stopname, direction, location, lat_str, lon_str;
        getline(parser, id_str, ',');
        getline(parser, route_str, ',');
        getline(parser, stopname, ',');
        getline(parser, direction, ',');
        getline(parser, location, ',');
        getline(parser, lat_str, ',');
        getline(parser, lon_str);

        int id, route;
        double lat, lon;
        id = stoi(id_str);
        route = stoi(route_str);
        lat = stod(lat_str);
        lon = stod(lon_str);

        BusStop B(id, route, stopname, direction, location, lat, lon);

        MapBusStops.push_back(B);
    }

    infile.close();

}

void BusStops::print() {
    sort(MapBusStops.begin(), MapBusStops.end(), 
        [](BusStop& b1, BusStop& b2) {return b1.ID < b2.ID; } );

    for (BusStop& busstop : MapBusStops) {
        busstop.print();
    }
}

//
// given a location, gives closest south and northbound bus stops
//
pair<BusStop, BusStop> BusStops::getClosest(pair<double, double> location) {
    BusStop south = this->MapBusStops.front();
    BusStop north = this->MapBusStops.front();
    
    double prevDist = INT_MAX;
    double currDist;
    for (BusStop& busstop : MapBusStops) {
        currDist = distBetween2Points(busstop.Lat, busstop.Lon, location.first, location.second);
        if (currDist < prevDist) {

            // changes nearest bus stops
            string direction = busstop.Direction;
            if (direction == "Southbound") {
                south = busstop;
            }
            else if (direction == "Northbound") {
                north = busstop;
            }

            prevDist = currDist;
        }
        else {
            prevDist = currDist;
        }
    }

    return make_pair(south, north);
}

//
// accessors / getters
//
int BusStops::getNumBusStops() const {
  return (int) this->MapBusStops.size();
}

