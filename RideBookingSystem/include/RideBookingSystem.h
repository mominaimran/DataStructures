#ifndef RIDEBOOKINGSYSTEM_H
#define RIDEBOOKINGSYSTEM_H

//coordinate all components of the system, manage data and implement core functionalities like booking rides, processing queues, and maintaining ride history.
#include <iostream>
#include "Passenger.h"
#include "Driver.h"
#include "Ride.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Graph.h"
#include "FileHandler.h"

using namespace std;

class RideBookingSystem
{
private:
    Passenger passengers[100];
    Driver drivers[100];
    Ride rides[100];
    LinkedList rideHistory;
    Queue rideQueue;
    Stack rideStack;
    Graph cityGraph;

    int passengerCount;
    int driverCount;
    int rideCount;

public:
    // Constructor
    RideBookingSystem();

    // Functions
    void registerPassenger();
    void registerDriver();

    void displayPassengers();
    void displayDrivers();

    void bookRide();
    void displayRides();

    bool isValidPassenger(int id);
    bool isValidDriver(int id);
    int findDriverIndex(int id);

    int findAvailableDriver();

    void processQueue();
    void completeRide(int driverId);
    void cancelLastRide();
    void displayRideHistory();

    int findNearestDriver(string pickup);
    void sortRidesByFare();

    void searchPassenger();
    void searchDriver();

    void displayDriverByIndex(int index);
};

#endif