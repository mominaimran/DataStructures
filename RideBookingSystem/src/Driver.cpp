#include "../include/Driver.h"
#include "ColorUtils.h"

// Constructor
Driver::Driver() {
    driverId = 0;
    name = "";
    phone = "";
    currentLocation = "";
    isAvailable = true;
    vehicle = "";
}

int Driver::getId() {
    return driverId;
}

string Driver::getName() {
    return name;
}

string Driver::getPhone() {
    return phone;
}

string Driver::getVehicle() {
    return vehicle;
}

bool Driver::getAvailability() {
    return isAvailable;
}

string Driver::getCurrentLocation() {
    return currentLocation;
}

void Driver::setId(int id) {
    driverId = id;
}

void Driver::setName(string n) {
    name = n;
}

void Driver::setPhone(string p) {
    phone = p;
}

void Driver::setVehicle(string v) {
    vehicle = v;
}

void Driver::setCurrentLocation(string loc) {
    currentLocation = loc;
}

void Driver::setAvailability(bool status) {
    isAvailable = status;
}

// Input function
void Driver::inputDriver() {
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Current Location: ";
    getline(cin, currentLocation);

    cout << "Enter Vehicle (Model + Number): ";
    getline(cin, vehicle);

    cout << "Is Driver Available? (1 = Yes, 0 = No): ";
    cin >> isAvailable;
}

// Display function
void Driver::displayDriver() {
    cout << YELLOW << "\n--- Driver Details ---\n" << RESET;
    cout << "Driver ID: " << driverId << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Current Location: " << currentLocation << endl;
    cout << "Vehicle: " << vehicle << endl;
    cout << "Availability: " << (isAvailable ? "Yes" : "No") << endl;
}
