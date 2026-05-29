#include "../include/Stack.h"

// Constructor
Stack::Stack() {
    top = -1;
}

// Check empty
bool Stack::isEmpty() {
    return top == -1;
}

// Check full
bool Stack::isFull() {
    return top == MAX - 1;
}

// PUSH
void Stack::push(Ride r) {

    if (isFull()) {
        cout << "Stack is full!\n";
        return;
    }

    arr[++top] = r;
}

// POP
Ride Stack::pop() {

    if (isEmpty()) {
        cout << "No ride to cancel!\n";
        return Ride();
    }

    return arr[top--];
}

// PEEK
Ride Stack::peek() {

    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return Ride();
    }

    return arr[top];
}