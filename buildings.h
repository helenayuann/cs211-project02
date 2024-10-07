/*buildings.h*/

//
// A collection of buildings in the Open Street Map
//
// Helena Yuan
// Northwestern University
// CS 211
//
// Original author: Prof. Joe Hummel

#pragma once
#include <vector>
#include "building.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>

using namespace std;
using namespace tinyxml2;

// 
// Keeps track of all the buildings in the map.
//
class Buildings
{
    public:
        vector<Building> MapBuildings;

        //
        // readMapBuildings
        //
        // Given an XML document, reads through the document and
        // stores all the buildings into the given vector.
        //
        
        void readMapBuildings(XMLDocument& xmldoc);

        //
        // accessors / getters
        //
        int getNumMapBuildings() const;

        //
        // prints all map buildings
        //
        void print();

        //
        // searches buildings for input and prints if found
        //
        void findAndPrint(string name, Nodes& nodes);
};
