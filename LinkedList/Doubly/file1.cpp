#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void forwardTraversal(Node* head){
    Node* temp = head;
    cout << "NULL ";
    while(temp!=NULL){
    cout << "<- " << temp->data << " -> ";
    temp = temp->next;
}
cout << "NULL\n";
}

void backwardTraversal(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    cout << "NULL";
    while(temp!=NULL){
        cout << "<-" << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    Node* first = new Node{10, NULL, NULL};
    Node* second = new Node{20, NULL, NULL};
    Node* third = new Node{30, NULL, NULL};

    head = first;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    forwardTraversal(head);
    //backwardTraversal(head);

    return 0;
}