#include "../include/RideBookingSystem.h"
#include "ColorUtils.h"

// Constructor
RideBookingSystem::RideBookingSystem()
{
    passengerCount = 0;
    driverCount = 0;
    rideCount = 0;

    FileHandler::loadPassengers(passengers, passengerCount);
    FileHandler::loadDrivers(drivers, driverCount);
    FileHandler::loadRides(rides, rideCount);
}

// Register Passenger
void RideBookingSystem::registerPassenger()
{

    if (passengerCount >= 100)
    {
        cout << "Passenger limit reached!\n";
        return;
    }

    int id;
    cout << YELLOW << "\n===== Register Passenger =====\n" << RESET;
    cout << "Enter Passenger ID: ";
    cin >> id;
    // duplicate check
    if (isValidPassenger(id)) {
        cout << "Passenger ID already exists!\n";
        return;
    }

    passengers[passengerCount].inputPassenger();
    passengerCount++;

    FileHandler::savePassenger(
        passengers[passengerCount - 1]);

    cout << GREEN << "Passenger Registered Successfully!\n" << RESET;
}

// Register Driver
void RideBookingSystem::registerDriver()
{
    if (driverCount >= 100)
    {
        cout << "Driver limit reached!\n";
        return;
    }

    int id;
    cout << YELLOW << "\n===== Register Driver =====\n" << RESET;
    cout << "Enter Driver ID: ";
    cin >> id;

    // duplicate check
    if (isValidDriver(id)) {
        cout << "Driver ID already exists!\n";
        return;
    }
    drivers[driverCount].setId(id);
    
    drivers[driverCount].inputDriver();
    driverCount++;
    FileHandler::saveDriver(drivers[driverCount - 1]);

    cout << GREEN << "Driver Registered Successfully!\n" << RESET;
}

// Display all passengers
void RideBookingSystem::displayPassengers()
{

    if (passengerCount == 0)
    {
        cout << "No Passengers Registered!\n";
        return;
    }

    cout << CYAN << "\n===== Passenger List =====\n" << RESET;

    for (int i = 0; i < passengerCount; i++)
    {
        passengers[i].displayPassenger();
    }
}

// Display all drivers
void RideBookingSystem::displayDrivers()
{

    if (driverCount == 0)
    {
        cout << RED << "No Drivers Registered!\n" << RESET;
        return;
    }

    cout << CYAN << "\n===== Driver List =====\n" << RESET;

    for (int i = 0; i < driverCount; i++)
    {
        drivers[i].displayDriver();
    }
}

bool RideBookingSystem::isValidPassenger(int id)
{
    for (int i = 0; i < passengerCount; i++)
    {
        if (passengers[i].getId() == id)
            return true;
    }
    return false;
}

bool RideBookingSystem::isValidDriver(int id)
{
    for (int i = 0; i < driverCount; i++)
    {
        if (drivers[i].getId() == id)
            return true;
    }
    return false;
}

int RideBookingSystem::findDriverIndex(int id)
{
    for (int i = 0; i < driverCount; i++)
    {
        if (drivers[i].getId() == id)
            return i;
    }
    return -1;
}

int RideBookingSystem::findAvailableDriver()
{

    for (int i = 0; i < driverCount; i++)
    {

        if (drivers[i].getAvailability())
        {
            return i; // first available driver
        }
    }

    return -1; // no driver found
}

void RideBookingSystem::bookRide()
{

    if (rideCount >= 100)
    {
        cout << "Ride limit reached!\n";
        return;
    }

    int pId;
    string pickup, drop;
    float fare;

    cout << CYAN << "\n--- Book Ride ---\n" << RESET;

    cout << "Enter Passenger ID: ";
    cin >> pId;

    if (!isValidPassenger(pId))
    {
        cout << "Invalid Passenger ID!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Pickup Location: ";
    getline(cin, pickup);

    cout << "Enter Drop Location: ";
    getline(cin, drop);

    cout << "Enter Fare: ";
    cin >> fare;

    Ride r;

    r.setRideId(rideCount + 1);
    r.setPassengerId(pId);
    r.setPickupLocation(pickup);
    r.setDropLocation(drop);
    r.setFare(fare);

    // 🔥 GRAPH DRIVER SELECTION
    int dIndex = findNearestDriver(pickup);

    // fallback if graph fails
    if (dIndex == -1)
    {
        dIndex = findAvailableDriver();
    }

    // CASE 1: DRIVER FOUND
    if (dIndex != -1)
    {

        r.setDriverId(drivers[dIndex].getId());
        r.setStatus("Booked");

        rides[rideCount++] = r;
        FileHandler::saveRide(r);

        // ALL STRUCTURES UPDATED
        rideHistory.insertRide(r);
        rideStack.push(r);

        drivers[dIndex].setAvailability(false);

        cout << GREEN << "Ride Booked Successfully with Driver ID: "
             << drivers[dIndex].getId() << endl << RESET;
    }

    // CASE 2: NO DRIVER
    else
    {

        r.setDriverId(-1);
        r.setStatus("Waiting");

        rideQueue.enqueue(r);

        cout << RED << "No driver available. Ride added to queue!\n" << RESET;
    }
}

void RideBookingSystem::completeRide(int driverId) {

    int dIndex = findDriverIndex(driverId);

    if (dIndex == -1) {
        cout << "Driver not found!\n";
        return;
    }

    // already free
    if (drivers[dIndex].getAvailability()) {
        cout << "This driver is already available!\n";
        return;
    }

    // booked → complete ride
    drivers[dIndex].setAvailability(true);

    cout << "Ride completed successfully!\n";
    cout << "Driver is now available!\n";

    processQueue();
}

void RideBookingSystem::displayRides()
{

    if (rideCount == 0)
    {
        cout << "No rides found!\n";
        return;
    }

    for (int i = 0; i < rideCount; i++)
    {
        rides[i].displayRide();
    }
}

void RideBookingSystem::displayRideHistory()
{

    cout << CYAN << "\n===== Ride History =====\n" << RESET;

    rideHistory.displayRides();
}

void RideBookingSystem::processQueue()
{

    int dIndex = findAvailableDriver();

    if (dIndex == -1)
        return;

    if (rideQueue.isEmpty())
        return;

    Ride r = rideQueue.dequeue();

    r.setDriverId(drivers[dIndex].getId());
    r.setStatus("Booked");

    rides[rideCount++] = r;

    rideHistory.insertRide(r);
    rideStack.push(r);

    drivers[dIndex].setAvailability(false);

    cout << GREEN << "Queued ride assigned to Driver ID: "
         << drivers[dIndex].getId() << endl << RESET;
}

void RideBookingSystem::cancelLastRide()
{
    if (rideStack.isEmpty())
    {
        cout << RED << "No ride to cancel!\n" << RESET;
        return;
    }

    Ride r = rideStack.pop();

    if (rideCount > 0)
    {
        rideCount--;
    }

    cout << GREEN << "Last ride cancelled successfully!\n" << RESET;
    cout << "Ride ID: " << r.getRideId() << " removed.\n";
}

int RideBookingSystem::findNearestDriver(string pickup)
{
    int pickupIndex = cityGraph.getIndex(pickup);

    if (pickupIndex == -1) {
        cout << "Invalid pickup location!\n";
        return -1;
    }

    int nearestIndex = -1;
    int minDistance = 9999;

    for (int i = 0; i < driverCount; i++) {

        if (drivers[i].getAvailability()) {

            int driverIndex =
                cityGraph.getIndex(drivers[i].getCurrentLocation());

            if (driverIndex == -1)
                continue;

            int dist =
                cityGraph.getDistance(pickupIndex, driverIndex);

            if (dist < minDistance) {
                minDistance = dist;
                nearestIndex = i;
            }
        }
    }

    return nearestIndex;
}

void RideBookingSystem::displayDriverByIndex(int index)
{
    drivers[index].displayDriver();
}

void RideBookingSystem::sortRidesByFare()
{

    for (int i = 0; i < rideCount - 1; i++)
    {

        for (int j = 0; j < rideCount - i - 1; j++)
        {

            if (rides[j].getFare() > rides[j + 1].getFare())
            {

                Ride temp = rides[j];
                rides[j] = rides[j + 1];
                rides[j + 1] = temp;
            }
        }
    }

    cout << GREEN << "Rides sorted by fare successfully!\n" << RESET;
}

void RideBookingSystem::searchPassenger() {

    int id;
    bool found = false;

    cout << "\nEnter Passenger ID: ";
    cin >> id;

    for (int i = 0; i < passengerCount; i++) {

        if (passengers[i].getId() == id) {

            cout << "\nPassenger Found!\n";
            passengers[i].displayPassenger();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Passenger not found!\n";
    }
}

void RideBookingSystem::searchDriver() {

    int id;
    bool found = false;

    cout << "\nEnter Driver ID: ";
    cin >> id;

    for (int i = 0; i < driverCount; i++) {

        if (drivers[i].getId() == id) {

            cout << "\nDriver Found!\n";
            drivers[i].displayDriver();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Driver not found!\n";
    }
}