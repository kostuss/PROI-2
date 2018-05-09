
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Trip.h"
#include "Trips.h"
using namespace std;

Trips::Trips() {};
Trips::~Trips() {
    tripVector.clear();
};
void Trips::endTripAt(int i) {
    if(i<tripVector.size())
        tripVector[i].endTrip();
    return;
}
void Trips::showTrips() {
    vector<Trip>::iterator it = tripVector.begin();
    cout << "List of trips:"<<endl;
    int i=1;
    for(it; it != tripVector.end(); ++it, ++i) {
        if (it->getCustName() != "#"){
            std::cout << "Trip: " << i << " details:"
                      << " Customer: " << it->getCustName() << " Driver: " << it->getDriverName()
                      << " VIP Trip : " << it->isVip() << "Is finished: " << it->isended()
                      << " Fare: " << it->getCost() << endl;
        }

    }
}
void Trips::addTrip(std::string driver, std::string customer, bool vip, int distance) {
    Trip trip(driver, customer,vip, distance);
    tripVector.push_back(trip);
}
void Trips::findLongest() {
    Trip longest = tripVector[0];
    unsigned long max;
    max=tripVector.size();
    for (int i=0;i<=(max-1);++i) {
        if (!(longest<tripVector[i])) {
            longest=tripVector[i];
        }
    }
    cout<< "The longest trip was " <<longest.getDistance()<<"km " <<endl;
}