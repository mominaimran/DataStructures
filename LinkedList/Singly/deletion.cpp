//removing nodes by changing links(no movement or shifting of elements like arrays)
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteAtStart(Node*& head){
    if(head==NULL){
        cout << "list empty";
        return;
    }
    Node* temp = head;
    head = head->next; //shift head pointer from current node to next
    delete temp;
}

void deleteAtPosition(Node*& head, int pos){
    if(head == NULL){
        cout << "List empty";
        return;
    }
    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    if(temp==NULL || temp->next==NULL){
        cout << "Invalid position";
        return;
    }

    for(int i=1; i<pos-1&&temp!=NULL; i++){
        temp = temp->next;
    }

    Node* delNode = temp->next;
    delete delNode;
}

void deleteByValue(Node*& head, int val){
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL && curr->data!=val){
        prev = curr;
        curr = curr->next;
    }

    if(curr==NULL){
        cout<<"Not found";
        return;
    }

    // deleting head
    if(prev==NULL)
        head = curr->next;
    else
        prev->next = curr->next;

    delete curr;
}

void deleteAfterVal(Node*& head, int target){
    if(head == NULL){
        cout << "List empty";
        return;
    }

    Node* curr = head;
    while(curr!=NULL && curr->data!=target){
        curr = curr->next;
    }
    if(curr == NULL || curr->next == NULL){
        cout << "deletion not possible";
    }
    Node* delNode = curr->next;
    curr->next = delNode->next;

    delete delNode;
}

void deleteBeforeVal(Node*& head, int target){
    if(head==NULL || head->next==NULL){
        cout<<"Deletion not possible";
        return;
    }

    // target is first node
    if(head->data == target){
        cout<<"Deletion not possible";
        return;
    }

    // delete head
    if(head->next->data == target){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prevPrev = head;
    Node* prev = head->next;
    Node* curr = head->next->next;

    while(curr!=NULL && curr->data != target){
        prevPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    if(curr==NULL){
        cout<<"Value not found";
        return;
    }

    prevPrev->next = curr;
    delete prev;
}

void deleteAtEnd(Node*& head){
    if(head==NULL){
        cout << "List empty";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* last = temp->next;
    temp->next = NULL;
    delete last;
}

void printList(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    Node* first = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};
    Node* fourth = new Node{40, NULL};

    head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;


    // deleteAtStart(head);
    // deleteBeforeVal(head, 20);
    deleteByValue(head, 10);
    printList(head);

    return 0;
}