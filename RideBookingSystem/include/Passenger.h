#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
using namespace std;

class Passenger
{
private:
    int passengerId;
    string name;
    string phone;
    string pickupLocation;

public:
    // Constructor
    Passenger();

    // Functions
    void inputPassenger();
    void displayPassenger();
    int getId();
    string getName();
    string getPhone();
    string getPickupLocation();

    void setId(int id);
    void setName(string name);
    void setPhone(string phone);
    void setPickupLocation(string pickup);
};

#endif