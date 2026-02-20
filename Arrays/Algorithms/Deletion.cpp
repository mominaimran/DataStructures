#include <iostream>
using namespace std;

void deletionAtStart(int arr[], int &size){
    if(size == 0){
        cout << "array is empty";
        return;
    }
    for(int i = 0; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

void deletionAtPosition(int arr[], int &size, int pos){
    if(size == 0){
        cout << "array is empty";
        return;
    }
    for(int i = pos-1; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

void deletionAtEnd(int &size){
    if(size == 0){
        cout << "array is empty";
        return;
    }
    size--;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    // deletionAtStart(arr, size);
    // deletionAtPosition(arr, size, 3);
    deletionAtEnd(size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}