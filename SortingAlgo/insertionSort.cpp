
#include<bits/stdc++.h>
using namespace std;

// Selection Sort: Finds the minimum element in the unsorted part
// of the array and swaps it with the first element of that part.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

// Bubble Sort: Repeatedly steps through the list, compares adjacent
// elements, and swaps them if they are in the wrong order.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization to stop if the array is sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // If no swaps occurred, the array is sorted
        }
    }
}

// Insertion Sort: Builds the final sorted array one item at a time.
// It iterates through the array and inserts each element into its correct
// position within the sorted part of the array.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// A helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 51, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Demonstration of Selection Sort
    cout << "Sorting using Selection Sort..." << endl;
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    
    cout << "----------------------" << endl;

    // Demonstration of Bubble Sort (re-initializing array)
    int arr2[] = {1, 2, 3, 51, 9};
    cout << "Original array for Bubble Sort: ";
    printArray(arr2, n);
    cout << "Sorting using Bubble Sort..." << endl;
    bubbleSort(arr2, n);
    cout << "Sorted array: ";
    printArray(arr2, n);

    cout << "----------------------" << endl;

    // Demonstration of Insertion Sort (re-initializing array)
    int arr3[] = {1, 2, 3, 51, 9};
    cout << "Original array for Insertion Sort: ";
    printArray(arr3, n);
    cout << "Sorting using Insertion Sort..." << endl;
    insertionSort(arr3, n);
    cout << "Sorted array: ";
    printArray(arr3, n);

    return 0;
}