#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(){
            front = rear = NULL;
        }

    void enqueue(int val){
        Node* newNode = new Node(val);
        if(front == NULL){
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front == NULL){
            cout << "Queue underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == NULL){
            rear = NULL;
        }
    }

    void display(){
        if(front == NULL){
            cout << "Queue Empty\n";
            return;
        }

        Node* temp = front;

        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.display();

    return 0;
}