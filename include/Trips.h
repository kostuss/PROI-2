#ifndef TRIPS_H_INCLUDED
#define TRIPS_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Drivers.h"
#include "Trip.h"
#include "Customers.h"

class Trips {
    std::vector <Trip> tripVector;

public:
    Trips();
    ~Trips();
    //print the list of trips
    void showTrips();
    //end given trip
    void endTripAt(int);
    //add a new trip
    void addTrip(std::string ,std::string, bool, int);
    // find the longest trip
    void findLongest();
};

#endif //TAKSOWKI_TRIPS_H
