#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED


class Driver {
    std::string name;
    bool vip;
    bool free;
    int earned;

public:
    Driver();
    Driver(std::string, bool);
    ~Driver();
    //return the name of driver
    std::string getName();
    //change the name of driver
    void setName(std::string);
    //return if driver is VIP
    bool isVIP() {return vip; }
    //return if driver is Free
    bool isFree() {return free;}
    void setVIP() {vip= true;};
    void setnotVIP() {vip = false;}
    void setFree() {free= true;}
    void setnotFree() {free= false;}
    // void earning (int);
    //int getEarning() { return earned;}

};

#endif