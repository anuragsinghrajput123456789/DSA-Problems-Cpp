#include<bits/stdc++.h>
using namespace std;

int main() {

    int rows = 3;

    // step 1: create array of row pointers
    int **arr = new int*[rows];

    // step 2: define column size for each row
    int colSize[3] = {2, 4, 3};

    // step 3: allocate memory for each row (different size)
    for(int i = 0; i < rows; i++){
        arr[i] = new int[colSize[i]];
    }

    // step 4: input values
    cout<<"Enter elements:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colSize[i]; j++){
            cin >> arr[i][j];
        }
    }

    // step 5: print jagged array
    cout<<"\nJagged array:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colSize[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // step 6: free memory
    for(int i = 0; i < rows; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}