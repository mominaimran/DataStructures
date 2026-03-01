#include <iostream>
using namespace std;

//1D array
int main() {
    int arr[5] = {1,2,3,4,5};
    //access
    cout << arr[4];
    //traversal
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    

    return 0;
}