#include <iostream>

using namespace std;

// The function name cannot start with a digit.
// The return type should be int, as it returns the index of the element.
int binarySearch2D(int arr[][3], int row, int col, int key) {
    int start = 0;
    int end = (row * col) - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int element = arr[mid / col][mid % col];

        if (element == key) {
            // Return the flat index.
            return mid;
        }

        if (element > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    // Return -1 if the key is not found.
    return -1;
}

// Fixed the print function to use correct dimensions and print elements on the same line.
void print2D(int arr[][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int key = 5;

    cout << "2D Array:" << endl;
    print2D(arr, 3, 3);

    int result = binarySearch2D(arr, 3, 3, key);

    if (result != -1) {
        cout << "Element " << key << " found at flat index " << result << endl;
        cout << "Corresponding row: " << result / 3 << ", column: " << result % 3 << endl;
    } else {
        cout << "Element " << key << " not found." << endl;
    }

    return 0;
}