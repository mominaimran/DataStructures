#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Ride.h"
using namespace std;

#define MAX 100

class Queue {
private:
    Ride arr[MAX];
    int front;
    int rear;
    int count;

public:
    Queue();

    bool isEmpty();
    bool isFull();

    void enqueue(Ride r);
    Ride dequeue();
    Ride peek();
};

#endif