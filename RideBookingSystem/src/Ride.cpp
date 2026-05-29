#include "../include/Ride.h"
#include "ColorUtils.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Ride::Ride() {
    rideId = 0;
    passengerId = 0;
    driverId = 0;
    pickupLocation = "";
    dropLocation = "";
    fare = 0;
    status = "Pending";
}

// Setters
void Ride::setRideId(int id) { rideId = id; }

void Ride::setPassengerId(int pId) { passengerId = pId; }

void Ride::setDriverId(int dId) { driverId = dId; }

void Ride::setPickupLocation(string pickup) { pickupLocation = pickup; }

void Ride::setDropLocation(string drop) { dropLocation = drop; }

void Ride::setFare(float f) { fare = f; }

void Ride::setStatus(string s) { status = s; }

// Getter
int Ride::getRideId() { return rideId; }

int Ride::getPassengerId() { return passengerId; }

int Ride::getDriverId() { return driverId; }

string Ride::getPickupLocation() { return pickupLocation; }

string Ride::getDropLocation() { return dropLocation; }

string Ride::getStatus() { return status; }

float Ride::getFare() {
    return fare;
}

// Display
void Ride::displayRide() {
    cout << YELLOW << "\n--- Ride Details ---\n" << RESET;
    cout << "Ride ID: " << rideId << endl;
    cout << "Passenger ID: " << passengerId << endl;
    cout << "Driver ID: " << driverId << endl;
    cout << "Pickup: " << pickupLocation << endl;
    cout << "Drop: " << dropLocation << endl;
    cout << "Fare: " << fare << endl;
    cout << "Status: " << status << endl;
}