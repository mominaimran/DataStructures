#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter no. of rows and cols: ";
    cin >> rows >> cols;

    //allocate memory
    int** arr = new int*[rows]; //Create an array containing rows number of integer pointers and store its starting address inside arr.

    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    cout << "Enter elements:\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //deallocate
    for(int i=0; i<rows; i++){
        delete[] arr[i];
    }
    delete [] arr;


    return 0;
}