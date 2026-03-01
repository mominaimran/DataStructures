#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void createList(Node*& head){
    Node* tail = NULL; //keep track of last node
    for(int i=0; i<3 ; i++){
        Node* newNode = new Node;
        newNode->data = i+1;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
}

void printList(Node* head){
    if(head==NULL){
        cout << "List empty";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data <<"->";
        temp = temp->next;
    }while(temp!=head);
    cout << "(head)";
}

int main() {
    Node* head = NULL;

    createList(head);
    printList(head);

    return 0;
}