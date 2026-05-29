#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
using namespace std;

class Driver
{
private:
    int driverId;
    string name;
    string phone;
    string vehicle;
    string currentLocation;
    bool isAvailable;

public:
    Driver();

    void inputDriver();
    void displayDriver();

    // Getters
    int getId();
    string getName();
    string getPhone();
    string getVehicle();
    string getCurrentLocation();
    bool getAvailability();

    // Setters
    void setId(int id);
    void setName(string n);
    void setPhone(string p);
    void setVehicle(string v);
    void setCurrentLocation(string loc);
    void setAvailability(bool status);
};

#endif