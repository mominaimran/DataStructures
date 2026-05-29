#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Ride.h"
using namespace std;

class Node {

public:
    Ride data;
    Node* next;

    Node(Ride r);
};

class LinkedList {

private:
    Node* head;

public:
    LinkedList();

    void insertRide(Ride r);
    void displayRides();
};

#endif