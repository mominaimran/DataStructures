#include <iostream>
using namespace std;

void enqueue(int cqueue[], int size, int &front, int &rear, int val){
    if((rear+1)%size == front ){
        cout << "queue if full\n";
        return;
    }

    if(front==-1) front = 0;

    rear = (rear+1)%size;
    cqueue[rear] = val;
}

void dequeue(int cqueue[], int size, int &front, int &rear){
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    int item = cqueue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
        return;
    }

    front = (front + 1) % size;
}

void circularPrint(int cqueue[], int front, int rear, int size){
    if(front == -1){
        cout << "Queue is empty\n";
    } else {
        int i = front;
        while(true){
            cout << cqueue[i] << " ";
            if(i == rear) break;
            i = (i + 1) % size;
        }
    }
}

int main() {
    int size = 4;
    int cqueue[size]={0};
    int front = -1, rear = -1;

    enqueue(cqueue, size, front, rear, 10);
    enqueue(cqueue, size, front, rear, 20);
    enqueue(cqueue, size, front, rear, 30);
    enqueue(cqueue, size, front, rear, 40);
    dequeue(cqueue, size, front, rear);
    dequeue(cqueue, size, front, rear);
    enqueue(cqueue, size, front, rear, 50);
    enqueue(cqueue, size, front, rear, 60);

    circularPrint(cqueue, front, rear, size);

    return 0;
}