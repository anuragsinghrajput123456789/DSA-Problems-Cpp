#include<iostream>
#include<climits>

using namespace std;

// This function checks if a target value is present in a 3x3 array.
bool isPresent(int arr[][3], int row, int col, int target) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// This function prints the 3x3 array.
void print(int arr[][3], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// This function prints the sum of each row.
void rowSum(int arr[][3], int row, int col) {
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// This function prints the sum of each column.
void colSum(int arr[][3], int row, int col) {
    for(int j = 0; j < col; j++) {
        int sum = 0;
        for(int i = 0; i < row; i++) {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// This function finds and prints the largest row sum and its index.
void largestRowSum(int arr[][3], int row, int col) {
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        if(sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "Maximum sum of a row is " << maxi << " and its index is: " << rowIndex << endl;
}

// This function finds and prints the largest column sum and its index.
void largestColSum(int arr[][3], int row, int col) {
    int maxi = INT_MIN;
    int colIndex = -1; // Changed to colIndex for clarity
    for(int j = 0; j < col; j++) {
        int sum = 0;
        for(int i = 0; i < row; i++) {
            sum += arr[i][j];
        }
        if(sum > maxi) {
            maxi = sum;
            colIndex = j; // The correct column index is 'j'
        }
    }
    cout << "Maximum sum of a column is " << maxi << " and its index is: " << colIndex << endl;
}


int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Print the array
    cout << "Printing the array:" << endl;
    print(arr, 3, 3);
    cout << endl;

    // Print the row sums
    cout << "Row sums are: ";
    rowSum(arr, 3, 3);
    cout << endl;

    // Print the column sums
    cout << "Column sums are: ";
    colSum(arr, 3, 3);
    cout << endl;

    // Find and print the largest row sum
    largestRowSum(arr, 3, 3);
    cout << endl;

    // Find and print the largest column sum
    largestColSum(arr, 3, 3);
    
    return 0;
}