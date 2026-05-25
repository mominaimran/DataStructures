#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void push(Node* &head, int val){
    Node* newNode = new Node{val, head}; 
    head = newNode; 
}

void pop(Node* &head){
    if(head == NULL){
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void peek(Node* head){
    if(head == NULL){
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top: " << head->data << endl;
}

void display(Node* head){
    if(head == NULL){
        cout << "Stack is empty\n";
        return;
    }

    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
    Node* head = NULL;

    push(head, 10);
    push(head, 20);
    push(head, 30);

    display(head);   // 30->20->10->NULL
    peek(head);      // Top: 30

    pop(head);
    display(head);   // 20->10->NULL

    pop(head);
    peek(head);      // Top: 10

    return 0;
}