
#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include "Customer.h"
// referance list of customers sorted by VIP
class Customers {
    std::vector<Customer*>customerVector ;
    Customer* front;

public:
    Customers();
    ~Customers();
    // Function to add new customer to the list
    void addCustomer(std::string,bool );
    // Print customers list
    void showCustomers();

    void pop();
    //Print separate Customer's details
    void printCustomer(Customer*);

    //Customer* getFront() {return front};
};

#endif //TAKSOWKI_CUSOMERS_H
