#include "../include/FileHandler.h"

void FileHandler::savePassenger(Passenger p) {

    ofstream file("data/passengers.txt", ios::app);

    if (!file) {
        cout << "File could not open!\n";
        return;
    }

    file << p.getId() << ","
         << p.getName() << ","
         << p.getPhone() << ","
         << p.getPickupLocation()
         << endl;

    file.close();
}

void FileHandler::loadPassengers(Passenger passengers[], int &count) {

    ifstream file("data/passengers.txt");

    if (!file) {
        cout << "No passenger file found!\n";
        return;
    }

    count = 0;

    int id;
    string name, phone, pickup;

    while (file >> id) {

        file.ignore(); // skip comma

        getline(file, name, ',');
        getline(file, phone, ',');
        getline(file, pickup);

        passengers[count].setId(id);
        passengers[count].setName(name);
        passengers[count].setPhone(phone);
        passengers[count].setPickupLocation(pickup);

        count++;
    }

    file.close();
}

void FileHandler::saveDriver(Driver d) {

    ofstream file("data/drivers.txt", ios::app);

    if (!file) {
        cout << "Driver file not opened!\n";
        return;
    }

    file << d.getId() << ","
         << d.getName() << ","
         << d.getPhone() << ","
         << d.getCurrentLocation() << ","
         << d.getVehicle() << ","
         << d.getAvailability()
         << endl;

    file.close();
}

void FileHandler::loadDrivers(Driver drivers[], int &count) {

    ifstream file("data/drivers.txt");

    if (!file) {
        cout << "No driver file found!\n";
        return;
    }

    count = 0;

    int id;
    string name, phone, location, vehicle;
    int availability;

    while (file >> id) {

        file.ignore(); // skip comma

        getline(file, name, ',');
        getline(file, phone, ',');
        getline(file, location, ',');
        getline(file, vehicle, ',');
        file >> availability;

        file.ignore(); // move to next line

        drivers[count].setId(id);
        drivers[count].setName(name);
        drivers[count].setPhone(phone);
        drivers[count].setCurrentLocation(location);
        drivers[count].setVehicle(vehicle);
        drivers[count].setAvailability(availability);

        count++;
    }

    file.close();
}

void FileHandler::saveRide(Ride r) {

    ofstream file("data/rides.txt", ios::app);

    if (!file) {
        cout << "Ride file not opening!\n";
        return;
    }

    file << r.getRideId() << ","
         << r.getPassengerId() << ","
         << r.getDriverId() << ","
         << r.getPickupLocation() << ","
         << r.getDropLocation() << ","
         << r.getFare() << ","
         << r.getStatus()
         << endl;

    file.close();
}

void FileHandler::loadRides(Ride rides[], int &count) {

    ifstream file("data/rides.txt");

    if (!file) {
        cout << "No ride file found!\n";
        return;
    }

    count = 0;

    int id, pId, dId;
    string pickup, drop, status;
    float fare;

    while (file >> id) {

        file.ignore();

        file >> pId;
        file.ignore();

        file >> dId;
        file.ignore();

        getline(file, pickup, ',');
        getline(file, drop, ',');

        file >> fare;
        file.ignore();

        getline(file, status);

        rides[count].setRideId(id);
        rides[count].setPassengerId(pId);
        rides[count].setDriverId(dId);
        rides[count].setPickupLocation(pickup);
        rides[count].setDropLocation(drop);
        rides[count].setFare(fare);
        rides[count].setStatus(status);

        count++;
    }

    file.close();
}