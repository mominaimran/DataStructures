#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int smallest = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
  int n;

    cout << "Enter size of an array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elems of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call any one sorting function
    insertionSort(arr, n);
    // selectionSort(arr, n);
    // bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}