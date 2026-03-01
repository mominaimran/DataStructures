#include <iostream>
using namespace std;

struct  Node{
    int data;
    Node* next;
};

int main() {
    //dynamic creation of linked list using user input
    Node* head = NULL;
    Node* temp = NULL; //last node tracker
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i<n ; i++){
        cout << "Enter data for node " << i+1 << ": ";
        cin >> val;

        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if(head==NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    //print
    cout << "Linked List: ";
    temp = head;
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}