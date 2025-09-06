#include <iostream>
using namespace std;

int main() {
    // Predefined rows and columns for the jagged array
    const int rows = 3;

    // Define column sizes for each row (this is what makes it jagged)
    const int cols[rows] = {2, 3, 1};  // Row 1 has 2 columns, Row 2 has 3 columns, Row 3 has 1 column

    // Dynamically allocate memory for the rows
    int** jaggedArray = new int*[rows];

    // Allocate memory for each row based on the column sizes defined in 'cols'
    for (int i = 0; i < rows; i++) {
        jaggedArray[i] = new int[cols[i]];  // Allocating memory for each row dynamically
    }

    // Assign values to the jagged array elements
    // Row 1
    jaggedArray[0][0] = 1;
    jaggedArray[0][1] = 2;

    // Row 2
    jaggedArray[1][0] = 3;
    jaggedArray[1][1] = 4;
    jaggedArray[1][2] = 5;

    // Row 3
    jaggedArray[2][0] = 6;

    // Print the jagged array
    cout << "\nJagged Array Elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];  // Free each row
    }
    delete[] jaggedArray;  // Free the array of pointers

    return 0;
}


/*

What is a Jagged Array in C++?

A jagged array is an array of pointers, where each pointer can point to a dynamically allocated array. Unlike a 2D array, where each row has the same number of columns, in a jagged array, each row can have a different number of columns.

*/