#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void deleteAtStart(Node*& head){
    if(head==NULL){
        cout << "Nothing to delete\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteAtEnd(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

void deleteByVal(Node*& head, int val){

}

void print(Node* head){
    Node* temp = head;
    cout << "NULL ";
    while(temp!=NULL){
    cout << "<- " << temp->data << " -> ";
    temp = temp->next;
}
cout << "NULL\n";
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

    deleteAtEnd(head);
    print(head);

    return 0;
}