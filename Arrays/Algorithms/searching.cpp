#include <iostream>
using namespace std;

void searchElement(int arr[], int size, int key){
    if (size <= 0){
        cout << "Array is empty";
        return;
    }

    for (int i = 0; i < size; i++){
        if (arr[i] == key){
            cout << key << " found at index " << i;
            return;
        }
    }

    cout << "Not found";
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    searchElement(arr, 5, 20);

    return 0;
}
