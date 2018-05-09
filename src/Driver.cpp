
#include <iostream>
#include <vector>
#include "Driver.h"

using namespace std;

Driver::Driver(const string name , bool vip ) {
    this->name = name;
    this->vip = vip;
    this->earned = 0;
    this->free= true;
}
Driver::Driver() = default;
Driver::~Driver() = default;

string Driver::getName() {
    return name;
}
void Driver::setName(string name) {
    this->name= name;
}
/*void Driver::earning(int money) {
    this->earned+=money;
} */
