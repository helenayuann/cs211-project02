/*busstops.h*/

//
// A collection of bus stops in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include "busstop.h"

using namespace std;

class BusStops
{
public:
    vector<BusStop> MapBusStops;

    //
    // constructor
    //
    // Given the name of a CSV file, input the data and
    // build a container of BusStop objects
    //
    BusStops(string filename);

    //
    // accessors / getters
    //
    int getNumBusStops() const;

    //
    // given a location, gives closest south and northbound bus stops
    //
    pair<BusStop, BusStop> getClosest(pair<double, double> location);

    //
    // prints all map bus stops
    //
    void print();



};