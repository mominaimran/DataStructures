#include <iostream>
using namespace std;

void updateArray(int arr[], int size, int index, int newVal){
    if(size==0){
        cout << "Array empty";
        return;
    }
    if(index<0 || index>=size){
        cout << "Invalid Index";
        return;
    }
    arr[index] = newVal;
}

int main() {
    int arr[5] = {1,2,3,4,5};

    updateArray(arr, 5, 1, 44);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}