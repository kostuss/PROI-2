#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

#include "Driver.h"
#include "Customer.h"
class Trip {
    std::string driver_name;
    std::string customer_name;
    bool vip;
    bool ended;
    int distance;
    static int basefare;
    static int VIPfare;
    int cost;
    void setCost();

public:
    Trip();
    ~Trip();
    // Constructor
    Trip(std::string, std::string,  bool ,int);
    // Change Distance of the trip
    void setDistance (int);
    // Return if trip is ended
    bool isended() {return ended;}
    // return if trip is VIP
    bool isVip() { return vip;}
    // end Trip
    void endTrip();
    // return cost of the trip
    int getCost() ;
    // return distance of the trip
    int getDistance();
    // return name of Customer
    std::string getCustName() {return customer_name;}
    // return name of the driver
    std::string getDriverName() { return driver_name;}
    // change customer name
    void setCustName(std::string) ;
    //change driver name
    void setDriverName(std::string);
    // overloaded operator to compare two trips on basis of length
    bool operator< (Trip& );
};

#endif //TRIP_H_INCLUDED
