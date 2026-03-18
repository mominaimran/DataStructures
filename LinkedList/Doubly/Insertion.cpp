#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void insertAtStart(Node*& head, int val){
    Node* newNode = new Node{val, NULL, NULL};
    if(head==NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node{val, NULL, NULL};

    if(head==NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int val, int pos){
    Node* newNode = new Node{val, NULL, NULL};

    if(head == NULL){
        head = newNode;
        return;
    }

    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    while(temp->next != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }

    Node* nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;

    if(nextNode != NULL){
        nextNode->prev = newNode;
    }
}

void insertByValue(Node*& head, int val, int targetVal){
    Node* newNode = new Node{val, NULL, NULL};

    if(head == NULL){
        cout << "List empty";
        return;
    }

    if(head->data == targetVal){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == targetVal){
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found";
}

void forwardTraversal(Node* head){
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
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    // insertAtPosition(head, 55, 2);
    insertByValue(head, 400, 40);

    forwardTraversal(head);
    
    return 0;
}