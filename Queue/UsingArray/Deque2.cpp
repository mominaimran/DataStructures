#include <iostream>
using namespace std;

const int SIZE = 4;
int dequeArr[SIZE];
int front = -1, rear = -1;

// 🔴 Check Empty
bool isEmpty() {
    return (front == -1);
}

// 🔴 Check Full
bool isFull() {
    return (front == (rear + 1) % SIZE);
}

// 🟢 Insert Front
void insertFront(int val) {
    if (isFull()) {
        cout << "Overflow\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE; // 🔥 backward
    }

    dequeArr[front] = val;
}

// 🟢 Insert Rear
void insertRear(int val) {
    if (isFull()) {
        cout << "Overflow\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE; // 🔥 forward
    }

    dequeArr[rear] = val;
}

// 🔵 Delete Front
void deleteFront() {
    if (isEmpty()) {
        cout << "Deque Empty\n";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE; // 🔥 forward
    }
}

// 🔵 Delete Rear
void deleteRear() {
    if (isEmpty()) {
        cout << "Deque Empty\n";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE; // 🔥 backward
    }
}

// 🧠 Display (IMPORTANT)
void display() {
    if (isEmpty()) {
        cout << "No value to display\n";
        return;
    }

    int i = front;

    while (true) {
        cout << dequeArr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE; // 🔥 circular traversal
    }
    cout << endl;
}

// 🚀 Driver
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();  // Expected: 2 5 10 20

    deleteRear();
    display();  // Expected: 2 5 10

    insertRear(99);
    display();  // Circular wrap happens here

    return 0;
}