#include<iostream>

using namespace std;

int main() {
    // We'll use a fixed size for this example.
    int n = 5;

    // 1. Correctly create a dynamic 2D array in heap memory.
    // This creates an array of 'n' pointers to integers.
    int **arr = new int*[n];

    // 2. The line `arr = {{},{}}` is incorrect for dynamic arrays and has been removed.
    // For a dynamic array, you must assign values in a loop after memory is allocated.

    // 3. Correctly allocate memory for each row.
    // This loop iterates through the 'n' pointers and makes each one point to a new
    // array of 'n' integers.
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    // Assigning values to the dynamically created array.
    // The nested loops are used to access each element individually.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // Assign a value to each cell.
            arr[i][j] = i * n + j;
        }
    }

    // Now, print the array to see the assigned values.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Correctly deallocate memory to prevent memory leaks.
    // You must delete each row first.
    for(int i = 0; i < n; i++){
        delete [] arr[i];
    }

    // 5. Then, deallocate the main array of pointers.
    delete [] arr;
    
    // Good practice: set the pointer to nullptr after deallocation.
    arr = nullptr;

    return 0;
}
