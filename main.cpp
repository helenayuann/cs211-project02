//
// Open Street Map
// 
// Helena Yuan
// Northwestern University
// CS 211
// 

#include <iostream>
#include <string>
#include <fstream>

#include "building.h"
#include "node.h"
#include "nodes.h"
#include "osm.h"
#include "tinyxml2.h"
#include "buildings.h"
#include "busstop.h"
#include "busstops.h"

using namespace std;
using namespace tinyxml2;

int main () 
{   
    cout << "** NU Open Street Map **" << endl;
    cout << endl;
    string filename;
    XMLDocument xmldoc;

    cout << "Enter map filename>" << endl;
    getline(cin, filename);

    osmLoadMapFile(filename, xmldoc);

    // initializes all node objects
    Nodes nodes;

    nodes.readMapNodes(xmldoc);
    cout << "# of nodes: " << nodes.getNumMapNodes() << endl;

    // initializes all building objects
    Buildings buildings;
    buildings.readMapBuildings(xmldoc);
    cout << "# of buildings: " << buildings.getNumMapBuildings() << endl;

    // initializes all bus stop objects
    BusStops busstops;
    busstops.readBusStops("bus-stops.txt");
    cout << "# of bus stops: " << busstops.getNumBusStops() << endl;

    // promts user for commands
    string command;
    while (command != "$") {
        cout << "Enter building name (partial or complete), or * to list, or $ to end" << endl;
        getline(cin, command);
        
        if (command == "$") { // ends loop
            break;
        }
        
        else if (command == "*") { // return list of all buildings
            buildings.print();
        } 

        else if (command == "@") { // return list of all bus stops
            busstops.print();
        }
        
        else { // output buildings that includes user input
            buildings.findAndPrint(command, nodes);
        }
    }

    // ending output summary
    //cout << endl;
    //cout << "** Done **" << endl;
    //
    //cout << "# of calls to getID(): " << Node::getCallsToGetID() << endl;
    //cout << "# of Nodes created: " << Node::getCreated() << endl;
    //cout << "# of Nodes copied: " << Node::getCopied() << endl;

    return 0;
}