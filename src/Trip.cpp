#include <iostream>
#include <vector>
#include "Driver.h"
#include "Customer.h"
#include "Trip.h"
#include "Customers.h"
using namespace std;

int Trip::basefare=1;
int Trip::VIPfare=2;

Trip::Trip(const string driver , const string customer, bool vip , int distance) {

    this->vip=vip;
    this->ended=false;
    this->distance=distance;
    this->cost=0;
    this->driver_name= driver;
    this->customer_name= customer;
}

Trip::~Trip() {}

void Trip::setCost() {
    if (vip) {cost= VIPfare*distance; }
    else cost= basefare*distance;
}
void Trip::endTrip() {
    this->ended= true;
    setCost();
}
int Trip::getCost() {
    setCost();
    return cost;
}
int Trip::getDistance() {
    return distance;
}
void Trip::setDistance(int distance) {
    this->distance=distance;
}
void Trip::setCustName(std::string name) {
    this->customer_name=name;
}
void Trip::setDriverName(std::string name) {
    this->driver_name=name;
}
bool Trip::operator< (Trip& a){
    return distance >= a.getDistance();
}