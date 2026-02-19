#include <iostream>
using namespace std;

void insertAtStart(int arr[], int size, int capacity, int val){
    if(size>=capacity){
        cout << "Array full";
    }
    for(int i = size-1; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = val;
}

void insertAtPosition(int arr[], int size, int capacity, int val, int pos){
    if(size>=capacity){
        cout << "Array full";
        return;
    }
    if(pos < 1 || pos > size + 1){
        cout << "Invalid position\n";
        return;
    }
    int index = pos-1;
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = val;
}

void insertAtEnd(int arr[], int size, int capacity, int val){
    if(size>=capacity){
        cout << "Array full";
    }
    arr[size] = val;
}

int main() {
    int arr[7] = {2,4,6,8};

    insertAtStart(arr, 4, 7, 0);
    insertAtEnd(arr, 5, 7, 10);
    insertAtPosition(arr, 6, 7, 44, 3);

    //print
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
