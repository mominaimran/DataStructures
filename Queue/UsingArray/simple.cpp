#include <iostream>
using namespace std;

const int SIZE = 2;     
int queue[SIZE];  
int front = -1, rear = -1;

// at rear
void enqueue(int val){
    if(rear == SIZE - 1){
        cout << "Queue overflow\n";
        return;
    }

    if(front == -1) front = 0;

    rear++;
    queue[rear] = val;
}

bool isEmpty(){
    return (front == -1);
}

// at front
void dequeue(){
    if(isEmpty()){
        cout << "Queue underflow\n";
        return;
    }
    
    int val = queue[front];
    front++;

    if(front > rear) front = rear = -1;
}

void display(){
    if(isEmpty()){
        cout << "No value to display\n";
        return;
    }

    for(int i = front; i <= rear; i++){
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Before deletion: \n";
    display();
    cout << "After deletion: \n";
    dequeue();
    display();

    return 0;
}