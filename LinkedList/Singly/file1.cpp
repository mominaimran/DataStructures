#include <iostream>
using namespace std;

//Node Structure
struct Node{
    int Data;
    Node* Next;
};

int main() {
    //manual nodes creation
    Node* head = NULL; 
    
    Node* first = new Node;// heap memory mein node bni jisko head point kr rha hai
    first->Data = 10;
    first->Next = NULL;

    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    //Linking Nodes
    head = first;
    first->Next = second;
    second->Next = third;

    //print list
    Node* temp = head;
    cout << "Head -> ";
    while(temp!=NULL){
        cout << temp->Data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL";

    return 0;
}