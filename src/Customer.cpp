#include <iostream>
#include <vector>
#include "Customer.h"

using namespace std;

Customer::Customer(const string name , bool vip ) {
    this->name = name;
    this->vip = vip;
    this->paid =0;
}
Customer::~Customer() {};
string Customer::getName() {
    return name;
}
void Customer::setName(const string name) {
    this->name= name;
}
void Customer::paying(int money) {
    this->paid+=money;
}
Customer* Customer::getLink() {
    return this->link;
}
void Customer::setLink(Customer* link) {
    this->link = link;
}