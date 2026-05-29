#include "../include/Queue.h"

// Constructor
Queue::Queue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Check empty
bool Queue::isEmpty() {
    return count == 0;
}

// Check full
bool Queue::isFull() {
    return count == MAX;
}

// ENQUEUE
void Queue::enqueue(Ride r) {

    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }

    rear = (rear + 1) % MAX;
    arr[rear] = r;
    count++;
}

// DEQUEUE
Ride Queue::dequeue() {

    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return Ride();
    }

    Ride r = arr[front];
    front = (front + 1) % MAX;
    count--;

    return r;
}

// PEEK
Ride Queue::peek() {

    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return Ride();
    }

    return arr[front];
}