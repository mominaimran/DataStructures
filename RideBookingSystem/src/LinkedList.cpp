#include "../include/LinkedList.h"

// Node constructor
Node::Node(Ride r) {
    data = r;
    next = nullptr;
}

// Linked list constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Insert ride at end
void LinkedList::insertRide(Ride r) {

    Node* newNode = new Node(r);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display all rides
void LinkedList::displayRides() {

    if (head == nullptr) {
        cout << "No ride history found!\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        temp->data.displayRide();
        temp = temp->next;
    }
}