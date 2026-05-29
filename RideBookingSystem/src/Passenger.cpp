#include "../include/Passenger.h"
#include "ColorUtils.h"

// Constructor
Passenger::Passenger() {
    passengerId = 0;
    name = "";
    phone = "";
    pickupLocation = "";
}

int Passenger::getId() {
    return passengerId;
}

string Passenger::getName() {
    return name;
}

string Passenger::getPhone() {
    return phone;
}

string Passenger::getPickupLocation() {
    return pickupLocation;
}

void Passenger::setId(int id) {
    passengerId = id;
}

void Passenger::setName(string name) {
    this->name = name;
}

void Passenger::setPhone(string phone) {
    this->phone = phone;
}

void Passenger::setPickupLocation(string pickup) {
    this->pickupLocation = pickup;
}

// Input function
void Passenger::inputPassenger(int id) {
    passengerId = id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Pickup Location: ";
    getline(cin, pickupLocation);
}

// Display function
void Passenger::displayPassenger() {
    cout << YELLOW << "\n--- Passenger Details ---\n" << RESET;
    cout << "Passenger ID: " << passengerId << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Pickup Location: " << pickupLocation << endl;
}