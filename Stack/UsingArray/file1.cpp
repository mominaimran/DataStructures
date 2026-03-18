#include <iostream>
using namespace std;

void push(int stack[], int size, int &top, int val){
    if(top == size-1){
        cout << "Stack Overflow\n";
        return;
    }

    top++;
    stack[top] = val;
}

void pop(int stack[], int &top){
    if(top == -1){
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Deleted: " << stack[top] << endl;
    top--;
}

void display(int stack[], int top){
    if(top == -1){
        cout << "Stack Empty\n";
        return;
    }

    for(int i = 0; i <= top; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main(){
    int size = 5;
    int stack[size];
    int top = -1;

    push(stack, size, top, 10);
    push(stack, size, top, 20);
    push(stack, size, top, 30);

    display(stack, top);

    pop(stack, top);

    display(stack, top);

}