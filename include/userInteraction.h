

#ifndef USERINTERACTION_H_INCLUDED
#define USERINTERACTION_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Driver.h"
#include "Drivers.h"
#include "Customer.h"
#include "Customers.h"
#include "Trip.h"
#include "Trips.h"

class UserInteraction{

private:
    Drivers driversList;
    Customers customersList;
    Trips tripsList;


public:
    UserInteraction();
    ~UserInteraction();
    //first function called from main
    void start();
    //choose beginning settings for company
    void initialize();
    void addDriver();
    void removeDriver();
    void showDrivers();
    void addTrip();
    void showTrips();
    void showCustomers();
    void endTrip();
    // show length of the longest trip
    void longestTrip();
    // call appropriate function based on choice
    void makeAChoice(int);
    // print Menu and read a choice of user
    int askForChoice();
    // template functions for reading from console, overloaded for setting a range for input
    template <typename T> T readAll(T bottom, T top);
    template <typename T> T readAll();
};
#endif //TAKSOWKI_USERINTERACTION_H
