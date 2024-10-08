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
#include "busstop.h"

using namespace std;

class BusStops
{
public:
    vector<BusStop> MapBusStops;

    //
    // readBusStops
    //
    // Given the name of a CSV file, input the data and
    // build a container of BusStop objects
    //
    void readBusStops(string filename);

    //
    // prints all map bus stops
    //
    void print();

};