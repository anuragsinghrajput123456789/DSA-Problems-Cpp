
#include<bits/stdc++.h>
using namespace std;

int main() {

    int row = 3;
    int col = 4;

    // step 1: create array of row pointers
    int **arr = new int*[row];

    // step 2: create each row (columns)
    for(int i = 0; i < row; i++){
        arr[i] = new int[col];
    }

    // step 3: input values
    cout << "Enter values:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    // step 4: print matrix
    cout << "\nMatrix:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // step 5: free memory (important)
    for(int i = 0; i < row; i++){
        delete [] arr[i];   // delete each row
    }

    delete [] arr;          // delete row pointers

    return 0;
}