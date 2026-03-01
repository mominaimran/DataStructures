#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void inserATStart(Node*& head, int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node*& head, int val, int pos){
    if(pos==1){
        inserATStart(head, val);
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1 && temp->next!=NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBeforeVal(Node*& head, int target, int val){
    if(head == NULL){
        cout << "List empty\n";
        return;
    }

    if(head->data == target){
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL && curr->data!=target){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout << "Value not found\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = curr;
    prev->next = newNode;
}

void insertAfterVal(Node*& head, int target, int val){
    if(head == NULL){
        cout << "List empty";
        return;
    }

    Node* curr = head;
    while(curr != NULL && curr->data != target){
        curr = curr->next;   // ✅ FIXED
    }

    if(curr == NULL){
        cout << "value not found";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;

    newNode->next = curr->next;
    curr->next = newNode;
}

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
    Node* first = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head = first;
    first->next = second;
    second->next = third;

    // insertAtPosition(head, 55, 2);
    // insertAtEnd(head, 100);
    insertAfterVal(head, 20, 44);
    printList(head);

    return 0;
}