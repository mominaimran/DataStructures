#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Ride.h"
using namespace std;

#define MAX 100

class Stack {

private:
    Ride arr[MAX];
    int top;

public:
    Stack();

    bool isEmpty();
    bool isFull();

    void push(Ride r);
    Ride pop();
    Ride peek();
};

#endif