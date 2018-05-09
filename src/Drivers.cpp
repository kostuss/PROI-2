#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Driver.h"
#include "Drivers.h"
using namespace std;

Drivers ::Drivers() = default;;

Drivers::~Drivers() {
    driverVector.clear();
}
string Drivers::getNameAt(int i) {
    if(i<driverVector.size())
        return driverVector[i].getName();
    else
        return "#";
}
void Drivers::removeDriver(string name, bool vip) {

    vector<Driver>::iterator it = driverVector.begin();
    for(it; it != driverVector.end(); ++it) {
        if(it->getName()==name && it->isVIP() == vip ) {
            driverVector.erase(it);
            cout << "Driver is fired!" << endl;
            return;
        }
    }
    cout << "probably, the driver you want to fire, is already fired!" << endl;
}
void Drivers :: addDriver(string name, bool vip) {
    Driver d(name,vip);
    driverVector.push_back(d);
}

void Drivers :: showDrivers() {
    vector<Driver>::iterator it = driverVector.begin();
    for(it; it != driverVector.end(); ++it) {
        if(it->getName()!="#")
            cout << " name: " << it->getName() << " VIP driver : "
                 << it->isVIP() << " is free: " << it->isFree()<< endl;
    }
}
void Drivers :: setDefault() {
    addDriver("John",true );
    addDriver("Paul",false );
    addDriver("Martin",true );
    addDriver("Thomas",true );
    addDriver("Peter",false );
    addDriver("Michael",false);
}
std::string Drivers:: findDriver(bool vip) {
    vector<Driver>::iterator it = driverVector.begin();
    if(vip) {
        for(it;it!=driverVector.end(); ++it) {
            if(it->isFree() && it->isVIP()) {
                it->setnotFree();
                return it->getName();
            }
        }

    } else {
        for (it;it!=driverVector.end();++it) {
            if(it->isFree() && !(it->isVIP())){
                it->setnotFree();
                return it->getName();
            }
        }
    }
}