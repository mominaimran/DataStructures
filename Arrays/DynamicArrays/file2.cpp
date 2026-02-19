#include <iostream>
using namespace std;

int main() {
    //2d dynamic
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    // Step 1: allocate row pointers
    int** arr = new int*[rows];

    //step 2: allocate each row
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    // step 3: Input
    cout << "Enter elements:\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }

    // Step 4: print
    cout << "Matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // step 5: deallocate
    for(int i=0; i<rows; i++){
        delete[] arr[i]; // deallocate each row
    }
    delete[] arr; // deallocate row pointers

    return 0;
}