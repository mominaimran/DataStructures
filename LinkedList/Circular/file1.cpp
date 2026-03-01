#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

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
    Node* first = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head = first;
    first->next = second;
    second->next = third;
    third->next = head;
    
    printList(head);

    return 0;
}