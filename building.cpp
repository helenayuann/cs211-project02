/*building.cpp*/

//
// A building in the Open Street Map.
// 
// Helena Yuan
// Northwestern University
// CS 211
// 

#include "building.h"

using namespace std;


//
// constructor
//
Building::Building(long long id, string name, string streetAddr)
  : ID(id), Name(name), StreetAddress(streetAddr)
{
  //
  // the proper technique is to use member initialization list above,
  // in the same order as the data members are declared:
  //
  //this->ID = id;
  //this->Name = name;
  //this->StreetAddress = streetAddr;

  // vector is default initialized by its constructor
}

//
// adds the given nodeid to the end of the vector.
//
void Building::add(long long nodeid)
{
  this->NodeIDs.push_back(nodeid);
}

//
// prints a building
//
void Building::print(const Nodes& nodes) {
  cout << Name << endl;
  cout << "Address: " << StreetAddress << endl;
  cout << "Building ID: " << ID << endl;
  cout << "# perimeter nodes: " << NodeIDs.size() << endl;

  /*
  cout << "Nodes:" << endl;

  
  double lat;
  double lon;
  bool isEntrance;
  for (long long id : NodeIDs) {
      if (nodes.find(id, lat, lon, isEntrance)) {
          cout << "  " << id << ": " << "(" << lat << ", " << lon << ")";
          if (isEntrance) {
              cout << ", is entrance";
          }
          cout << endl;
      }
      else {
          cout << "  " << id << ": " << "** NOT FOUND **" << endl;
      }
  }
  */
}