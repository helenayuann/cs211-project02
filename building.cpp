/*building.cpp*/

//
// A building in the Open Street Map.
// 
// Helena Yuan
// Northwestern University
// CS 211
// 

#include <utility>

#include "building.h"
#include "node.h"
#include "nodes.h"
#include "busstop.h"
#include "busstops.h"
#include "dist.h"
#include "curl_util.h"
#include "json.hpp"

using json = nlohmann::json;
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
void Building::print(const Nodes& nodes, BusStops& busstops, CURL* curl) {
  cout << Name << endl;
  cout << "Address: " << StreetAddress << endl;
  cout << "Building ID: " << ID << endl;
  cout << "# perimeter nodes: " << NodeIDs.size() << endl;

  // gives location
  pair<double, double> P = getLocation(nodes);
  cout << "Location: (" << P.first << ", " << P.second << ")" << endl;

  // gives closest bus stops
  pair<BusStop, BusStop> closest = busstops.getClosest(P);
  BusStop south = closest.first;
  BusStop north = closest.second;
  double southDist = distBetween2Points(south.Lat, south.Lon, P.first, P.second);
  double northDist = distBetween2Points(north.Lat, north.Lon, P.first, P.second);
  cout << "Closest Southbound bus stop:" << endl;
  cout << "  " << south.ID << ": " << south.StopName << ", bus #" << south.Route << ", " << south.Location << ", " << southDist << " miles" << endl;
  cout << "Closest Northbound bus stop:" << endl;
  cout << "  " << north.ID << ": " << north.StopName << ", bus #" << north.Route << ", " << north.Location << ", " << northDist << " miles" << endl;

  // bus arrival predictions
  string sroute_str = to_string(south.Route);
  string sid_str = to_string(south.ID);
  string nroute_str = to_string(north.Route);
  string nid_str = to_string(north.ID);
  string south_url = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=95MkKqznLPwDcKQa7sxHNcXdz&rt=" + sroute_str + "&stpid=" + sid_str + "&format=json";
  string north_url = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=95MkKqznLPwDcKQa7sxHNcXdz&rt=" + nroute_str + "&stpid=" + nid_str + "&format=json";

  // south bus prediction
  string south_response;
  if (!callWebServer(curl, south_url, south_response)) {
    cout << "  <<bus predictions unavailable, call failed>>" << endl;
  }
  else {
    

  }
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

//
// gets the center(lat, lon) of the building based
// on the nodes that form the perimeter
//
pair<double, double> Building::getLocation (const Nodes& nodes) {
  double lat;
  double lon;
  bool isEntrance;
  double totalLat;
  double totalLon;
  double avgLat;
  double avgLon;

  for (long long id : NodeIDs) {
      if (nodes.find(id, lat, lon, isEntrance)) {
        totalLat = totalLat + lat;
        totalLon = totalLon + lon;
      }
  }

  avgLat = totalLat / NodeIDs.size();
  avgLon = totalLon / NodeIDs.size();

  return make_pair(avgLat, avgLon);
}