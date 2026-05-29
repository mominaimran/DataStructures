#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include "Passenger.h"
#include "Driver.h"
#include "Ride.h"

using namespace std;

class FileHandler {

public:
    static void savePassenger(Passenger p);
    static void loadPassengers(Passenger passengers[], int &count);

    static void saveDriver(Driver d);
    static void loadDrivers(Driver drivers[], int &count);

    static void saveRide(Ride r);
    static void loadRides(Ride rides[], int &count);
};

#endif