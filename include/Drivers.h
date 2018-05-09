//
// Created by damian on 07.05.18.
//

#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Driver.h"
class Drivers {
    std::vector <Driver> driverVector;

public:
    Drivers();
    ~Drivers();
    //Return the name of driver at given position
    std::string getNameAt(int);
    //add few default drivers
    void setDefault();
    //add driver
    void addDriver(std::string , bool);
    //realse the worker from company
    void removeDriver(std::string , bool);
    // Print drivers list
    void showDrivers();
    // Finds free driver
    std::string findDriver(bool);
};


#endif //TAKSOWKI_DRIVERS_H
