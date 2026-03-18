#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtStart(Node*& head, int val){
    Node* newNode = new Node{val, NULL};
    if(head==NULL){
        head = newNode;
        newNode->next = head;
    }else{
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node*& head, int val){
    Node* newNode = new  Node{val, NULL};

    if(head==NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    Node*temp = head;
    do{
        temp = temp->next;
    }while(temp->next!=head); //find/reach last node 
    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(Node*& head, int val, int pos){
    if(pos <= 0){
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node{val, NULL};
    //empty list
    if(head==NULL){
        if(pos==1){
            head = newNode;
            newNode->next = head;
        }else{
            cout << "position invalid";
        }
        return;
    }

    //insert at start
    if(pos==1){
        Node* last = head;
        while(last->next!=head){
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return;
    }

    //insert at middle/end
    Node* temp = head;
    int i=1;
    while(i<pos-1 && temp->next!=head){
        temp = temp->next;
        i++;
    }
    //position out of bounds
    if(i != pos-1){
        cout << "Position invalid\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeVal(Node*& head, int target, int val){
    if(head==NULL){
        cout << "list is empty";
        return;
    }

    Node* newNode = new Node{val, NULL};
    //case 1: insert before head
    if(head->data==target){
        Node* last = head;
        while(last->next!=head){
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return;
    }

    //case 2: normal case
    Node* prev = head;
    Node* curr = head->next;
    while(curr != head && curr->data!=target){
        prev = curr;
        curr = curr->next;
    }
    if(curr==head){
        cout << "value not found";
        return;
    }
    prev->next = newNode;
    newNode->next = curr;
}

void insertAfterVal(Node*& head, int target, int val){
    Node* newNode = new Node{val, NULL};

    if(head == NULL){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    do{
        if(temp->data == target){
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }while(temp!=head);

    cout << "Value Not Found";
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
    }while(temp!=head); //full circle traversal
    cout << "(head)";
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

    // insertAtStart(head, 100);
    // insertAtEnd(head, 200);
    // insertAtPosition(head, 500, 3);
    // insertBeforeVal(head, 20, 44);
    insertAfterVal(head, 50, 44);
    printList(head);

    return 0;
}