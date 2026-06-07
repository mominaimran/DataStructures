#include <iostream>
#include "include/RideBookingSystem.h"
#include "ColorUtils.h"

using namespace std;

int main()
{
    RideBookingSystem system;
    int choice;

    do
    {
        cout << CYAN
             << "\n=====================================\n";
        cout << "       RIDE BOOKING SYSTEM\n";
        cout << "=====================================\n"
             << RESET;

        cout << GREEN << "1. " << RESET << "Register Passenger\n";
        cout << GREEN << "2. " << RESET << "Register Driver\n";
        cout << GREEN << "3. " << RESET << "Display Passengers\n";
        cout << GREEN << "4. " << RESET << "Display Drivers\n";
        cout << GREEN << "5. " << RESET << "Book Ride\n";
        cout << GREEN << "6. " << RESET << "Display Rides\n";
        cout << GREEN << "7. " << RESET << "Display Ride History\n";
        cout << GREEN << "8. " << RESET << "Complete Ride\n";
        cout << RED << "9. " << RESET << "Cancel Last Ride\n";
        cout << GREEN << "10. " << RESET << "Sort Rides by Fare\n";
        cout << GREEN << "11. " << RESET << "Find Nearest Driver\n";
        cout << GREEN << "12. " << RESET << "Search Passenger\n";
        cout << GREEN << "13. " << RESET << "Search Driver\n";
        cout << RED << "14. " << RESET << "Exit\n";

        cout << CYAN << "\nEnter choice: " << RESET;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << GREEN << "\nRegistering Passenger...\n"
                 << RESET;
            system.registerPassenger();
            break;

        case 2:
            cout << GREEN << "\nRegistering Driver...\n"
                 << RESET;
            system.registerDriver();
            break;

        case 3:
            cout << CYAN << "\nPassengers\n"
                 << RESET;
            system.displayPassengers();
            break;

        case 4:
            cout << CYAN << "\nDrivers\n"
                 << RESET;
            system.displayDrivers();
            break;

        case 5:
            cout << GREEN << "\nBooking Ride...\n"
                 << RESET;
            system.bookRide();
            break;

        case 6:
            cout << CYAN << "\nRide Details\n"
                 << RESET;
            system.displayRides();
            break;

        case 7:
            cout << CYAN << "\nRide History\n"
                 << RESET;
            system.displayRideHistory();
            break;

        case 8:
        {
            int driverId;
            cout << CYAN << "Enter Driver ID: " << RESET;
            cin >> driverId;

            system.completeRide(driverId);
            break;
        }

        case 9:
            cout << RED << "\nCancelling Last Ride...\n"
                 << RESET;
            system.cancelLastRide();
            break;

        case 10:
            cout << GREEN << "\nSorting Rides...\n"
                 << RESET;
            system.sortRidesByFare();
            break;

        case 11:
        {
            string pickup;

            cout << CYAN
                 << "Enter Pickup Location: "
                 << RESET;

            cin >> pickup;

            int nearestDriver =
                system.findNearestDriver(pickup);

            if (nearestDriver != -1)
            {
                cout << GREEN
                     << "\nNearest Driver Found:\n"
                     << RESET;

                system.displayDriverByIndex(nearestDriver);
            }
            else
            {
                cout << RED
                     << "No driver found!\n"
                     << RESET;
            }

            break;
        }

        case 12:
            cout << GREEN << "\nSearching Passenger...\n"
                 << RESET;
            system.searchPassenger();
            break;

        case 13:
            cout << GREEN << "\nSearching Driver...\n"
                 << RESET;
            system.searchDriver();
            break;

        case 14:
            cout << RED
                 << "\nExiting Ride Booking System...\n"
                 << RESET;
            break;

        default:
            cout << RED
                 << "\nInvalid choice!\n"
                 << RESET;
        }

    } while (choice != 14);

    return 0;
}