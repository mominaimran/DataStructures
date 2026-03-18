#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteAtSart(Node*& head){
    if(head==NULL){
        cout << "List is empty";
        return;
    }

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head;
    Node* temp = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    delete temp;
}

void deleteAtEnd(Node* head){
    if(head == NULL){
        cout<<"List empty";
        return;
    }

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    while(curr->next != head){
        prev = curr;
        curr = curr->next;
    }
    prev->next = head;
    delete curr;
}

void deleteByPosition(Node*& head, int pos){
    if(pos <= 0){
        cout<<"Invalid position";
        return;
    }

    if(head==NULL){
        cout << "List is empty";
        return;
    }

    if(pos==1){
        if(head->next==head){
            delete head;
            head = NULL;
            return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;   
    }

    Node* prev = NULL;
    Node* curr = head;
    int i = 1;
    while(i < pos && curr->next != head){
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(i < pos){
        cout<<"Invalid position";
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void deleteByValue(Node*& head, int val){
    if(head == NULL){
        cout << "List is empty";
        return;
    }

    // Case 1: value at head
    if(head->data == val){
        if(head->next == head){ // single node
            delete head;
            head = NULL;
            return;
        }
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;
    }

    // Case 2: value in non-head nodes
    Node* prev = head;
    Node* curr = head->next;

    while(curr != head && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    if(curr == head){
        cout << "Value not found";
        return;
    }

    prev->next = curr->next;
    delete curr;
}

void printList(Node* head){
    Node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp!=head);
    cout << "head";
}

int main() {
    Node* head = NULL;
    Node* first = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head = first;
    first->next = second;
    second->next = third;
    third->next = head;

    // deleteAtEnd(head);
    // deleteByPosition(head, 1);
    deleteByValue(head, 30);
    printList(head);
    
    return 0;
}