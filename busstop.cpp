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

void BusStop::print() {
    cout << ID << ": bus " << Route << ", " << StopName << ", " << Location << ", " << Direction << ", location (" << Lat << ", " << Lon << ")" << endl;
}