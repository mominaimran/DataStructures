#include <iostream>
using namespace std;

int SIZE = 5;
int stack[5];
int top = -1;

bool isFull(){
    return top == SIZE-1;
}

bool isEmpty(){
    return top==-1;
}

void push(int val){
    if(isFull()){
        cout << "Stack Overflow\n";
        return;
    }

    top++;
    stack[top] = val;
}

void pop(){
    if(isEmpty()){
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Deleted: " << stack[top] << endl;
    top--;
}

void peek(){
    if(isEmpty()){
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Top element: " << stack[top] << endl;
}

void display(){
    if(isEmpty()){
        cout << "Stack Empty\n";
        return;
    }

    for(int i = 0; i <= top; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main(){
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();

}