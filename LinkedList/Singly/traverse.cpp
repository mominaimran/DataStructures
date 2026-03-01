#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void createList(Node*& head){
    Node* temp = NULL;
    for(int i=0; i<3; i++){
        Node* newNode = new Node;
        newNode->data = i+1;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode; //linking must happen before moving the pointer
            temp = newNode;
        }
    }
}

//traverse and print
void printList(Node* head){
    if(head == NULL){
        cout << "list is empty";
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    createList(head);
    printList(head);

    return 0;
}