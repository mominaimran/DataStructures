#include <iostream>
using namespace std;

const int SIZE = 4;
int deque[SIZE];
int front = -1, rear = -1;

bool isFull(){
    return rear == SIZE - 1;
}

bool isEmpty(){
    return front == -1;
}

void insertFront(int val){
    if(front == 0){   
        cout << "Overflow at front\n";
        return;
    }
    if(front == -1){
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = val;
}

void insertRear(int val){
    if(isFull()){
        cout << "Overflow at rear\n";
        return;
    }
    if(front == -1){  
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
}

void deleteFront(){
    if(isEmpty()){
        cout << "Deque empty\n";
        return;
    }
    if(front == rear){
        front = rear = -1;
    } else {
        front++;
    }
}

void deleteRear(){
    if(isEmpty()){
        cout << "Deque empty\n";
        return;
    }
    if(front == rear){
        front = rear = -1;
    } else {
        rear--;
    }
}

void display(){
    if(isEmpty()){
        cout << "No value to display\n";
        return;
    }

    for(int i = front; i <= rear; i++){
        cout << deque[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "insert rear: ";
    insertRear(40);
    display();

    cout << "insert rear: ";
    insertRear(30);
    display();

    cout << "delete front: ";
    deleteFront();
    display();

    cout << "insert front: ";
    insertFront(20); 
    deleteRear();  
    display();


    return 0;
}