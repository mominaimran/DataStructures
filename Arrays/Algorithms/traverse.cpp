#include <iostream>
using namespace std;

void traverseArray(int arr[], int size){
    if(size<=0){
        cout << "array is empty";
        return;
    } 

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    traverseArray(arr, 5);

    return 0;
}