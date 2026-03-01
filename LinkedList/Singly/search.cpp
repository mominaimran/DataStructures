#include <iostream>
using namespace std;
//changing links -> rewiring
//just walking -> traversal
struct Node{
    int data;
    Node* next;
};

void createList(Node*& head, int n){
    Node* temp = NULL;
    for(int i=1; i<=n; i++){
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }
} 

void printList(Node* head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

void searchNode(Node* head, int targetVal){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == targetVal){
            cout << "value found";
            return;
        }
        temp = temp->next;
    }
    cout << "not found";
}

int main() {
    Node* head = NULL;
    int n;
    cout << "Enter nodes you want to create: ";
    cin >> n;
    createList(head, n);
    printList(head);
    searchNode(head, 6);

    return 0;
}