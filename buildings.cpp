/*buildings.cpp*/

//
// A collection of buildings in the Open Street Map
// 
// Helena Yuan
// Northwestern University
// CS 211
// 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#include "buildings.h"
#include "osm.h"
#include "tinyxml2.h"

using namespace std;

//
// readMapBuildings
// 
// Given an XML document, reads through the document and
// stores all buildings into given vector.
//
void Buildings::readMapBuildings(XMLDocument& xmldoc) {
    XMLElement* osm = xmldoc.FirstChildElement("osm");
    XMLElement* way = osm->FirstChildElement("way");

    // loops through all the ways
    while (way != nullptr)
    {
        if (osmContainsKeyValue(way, "building", "university")) {
            string name = osmGetKeyValue(way, "name");

            string streetAddr = osmGetKeyValue(way, "addr:housenumber") 
            + " "
            + osmGetKeyValue(way,"addr:street");

            const XMLAttribute* attribute = way->FindAttribute("id");
            long long id = attribute->Int64Value();

            XMLElement* nd = way->FirstChildElement("nd");
            Building B(id, name, streetAddr);
            
            // loops through each node definition
            while (nd != nullptr)
            {
                const XMLAttribute* ndref = nd->FindAttribute("ref");
                assert(ndref!= nullptr);

                long long id = ndref->Int64Value();
                B.add(id);

                nd = nd->NextSiblingElement("nd");
            }
            MapBuildings.push_back(B);
        }
        way = way->NextSiblingElement("way");
    }
}

// 
// accessors / getters
//
int Buildings::getNumMapBuildings() const {
  return (int) this->MapBuildings.size();
}

//
// prints all map buildings
//
void Buildings::print () {
    for (Building& building : MapBuildings) {
                cout << building.ID << ": " << building.Name << ", " << building.StreetAddress << endl;
            }
}

//
// searches buildings for input and prints if found
//
void Buildings::findAndPrint(string name, Nodes& nodes) {
    bool found = false;
    for (Building& building : MapBuildings) {
        if (building.Name.find(name) != string::npos) {
            found = true;
            building.print(nodes);
        }
    }

    //if building not found
    if (found == false) {
        cout << "No such building" << endl;
    }
}