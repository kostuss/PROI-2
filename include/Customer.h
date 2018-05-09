

#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>

class Customer {
    std::string name;
    bool vip;
    int paid;
    Customer* link;

public:
    //default class constructor
    Customer();
    //class constructor
    Customer(std::string, bool);
    //default class destructor
    ~Customer();
    //return name of customer
    std::string getName();
    // return if customer is VIP
    bool isVIP() {return vip; }
    void setVIP() {vip= true;}
    void setnotVIP() {vip = false;}
    //Change name of customer
    void setName (std::string) ;

    void paying(int money);
    //return the pointer to the next customer (used in class Customers)
    Customer* getLink();
    // set the pointer to the next customer (used in class Customers)
    void setLink(Customer*);

};
#endif //TAKSOWKI_CUSTOMER_H
