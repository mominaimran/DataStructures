#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <string>
using namespace std;

class Ride {
private:
    int rideId;
    int passengerId;
    int driverId;

    string pickupLocation;
    string dropLocation;

    float fare;
    string status;

public:
    Ride();

    void inputRide();
    void displayRide();

    void setRideId(int id);
    void setPassengerId(int pId);
    void setDriverId(int dId);
    void setPickupLocation(string pickup);
    void setDropLocation(string drop);
    void setFare(float f);
    void setStatus(string s);

    int getRideId();
    float getFare();
    int getPassengerId();
    int getDriverId();
    string getPickupLocation();
    string getDropLocation();
    string getStatus();
};

#endif