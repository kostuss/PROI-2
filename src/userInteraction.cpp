#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Driver.h"
#include "Drivers.h"
#include "Customer.h"
#include "Customers.h"
#include "Trip.h"
#include "Trips.h"
#include "userInteraction.h"

using namespace std;

UserInteraction:: UserInteraction() = default;

UserInteraction::~UserInteraction() = default;

void UserInteraction:: start() {
    initialize();

    while(1) {
        int choice = askForChoice();
        makeAChoice(choice);
    }

}
void UserInteraction::initialize() {

    cout << "Welcome to Taxi Company" << endl;
    cout << "Do you want to add few default drivers or do it at your own?"<<endl;
    cout << " 1. to add default drivers\n" << " 2. do not add any drivers\n";
    int choice = readAll<int>( 1, 2);
    if (choice==1) driversList.setDefault();


}
void UserInteraction:: addDriver() {
    string name;
    bool vip;
    int choice;
    cout << "Enter worker name ";
    cin >> name;
    if(name=="#") {
        name = "##";
        cout << "# forbiden - altered to ##" << endl;
    }
    cout << "Is it VIP driver. Enter 1 if yes 0 if no ";
    vip = readAll<bool>(0,1);
    driversList.addDriver(name,vip);
}
void UserInteraction:: removeDriver() {
    string name;
    bool vip;
    cout << "Enter Driver name to remove ";
    cin >> name;
    cout << "Enter 1 if vip 0 if not ";
    vip = readAll<bool>(0,1);
    driversList.removeDriver(name,vip );
}
void UserInteraction::makeAChoice(int choice) {
    switch(choice)
    {
        case 1: { addDriver(); break; }
        case 2: { removeDriver(); break; }
        case 3: { addTrip(); break; }
        case 4: { showDrivers(); break; }
        case 5: { showCustomers(); break; }
        case 6: { showTrips(); break;}
        case 7: { endTrip(); break;}
        case 8: { longestTrip(); break;}
        case 9: { exit(0); }
        default :{ cout<<"Wrong choice\n"; break;}
    }
}
void UserInteraction::addTrip()  {
    string driver;
    string customer;
    bool vip;
    int distance;
    cout <<"Provide details for the new trip:"<<endl;
    cout <<"Give customer name: ";
    cin >> customer;
    cout <<"Is it vip customer: 1 if yes 0 if no: " ;
    vip= readAll<bool>(0,1);
    cout <<"How long is the trip: ";
    distance= readAll<int>();
    driver= driversList.findDriver(vip);
    tripsList.addTrip(driver,customer,vip,distance);
    customersList.addCustomer(customer,vip);
}
void UserInteraction::endTrip() {
    int choice;
    cout<<"Choose which trip you want to end" ;
    tripsList.showTrips() ; cout <<endl;
    cout <<endl <<"Your choice:";
    choice=readAll<int>();
    choice-=1;
    tripsList.endTripAt(choice);
}
void UserInteraction:: showDrivers() {
    driversList.showDrivers();
}
void UserInteraction::showCustomers() {
    customersList.showCustomers();
}
void UserInteraction::showTrips() {
    tripsList.showTrips();
}
void UserInteraction::longestTrip() {
    tripsList.findLongest();
}
int UserInteraction :: askForChoice() {

    cout<<" \nThis is Taxi Company " << endl;
    cout<<" 1.Add a driver\n";
    cout<<" 2.Remove a driver\n";
    cout<<" 3.Add a new Trip\n";
    cout<<" 4.Show driver list\n";
    cout<<" 5.Show customer list\n";
    cout<<" 6.Show Trip list\n ";
    cout<<" 7.End Trip\n";
    cout<<" 8.Show distance of the longest trip\n";
    cout<<" 9.Quit \n";
    cout<<"Enter your choice: ";
    return readAll<int>(1,9);
}

template <typename T> T
UserInteraction :: readAll(T bottom, T top) {
    T c;
    bool check;
    do{
        check = 0;
        cin >> c;
        if(!cin) {
            check = 1;
            cout << "Wrong symbol" << endl;
        } else {
            if(c<bottom || c > top) {
                check = 1;
                cout << "Enter symbol between " << bottom << " and " << top << " \n";
            }
        }
        cin.clear();
        cin.ignore(256, '\n');

    }while(check);
    return c;
}
template <typename T> T
UserInteraction :: readAll() {
    T c;
    bool check;
    do{
        check = 0;
        cin >> c;
        if(!cin) {
            check = 1;
            cout << "Wrong symbol" << endl;
        }
        else {
            cout << "Wrong symbol\n";
        }

        cin.clear();
        cin.ignore(256, '\n');

    }while(check);
    return c;
}