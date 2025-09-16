#include<bits/stdc++.h>
using namespace std; 

// Iterative Bubble Sort
void bubbleSort(int *arr, int n) {
    if (n == 0 || n == 1) return; 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Recursive Bubble Sort
void bubbleSortRec(int *arr, int n) {
    // base case 
    if (n == 0 || n == 1) return; 

    // One pass of bubble sort, largest element moved to end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }

    // recursive call
    bubbleSortRec(arr, n - 1);
}

// Merge function
void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1; 
    int len2 = e - mid; 

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s; 

    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1; 

    for (int j = 0; j < len2; j++) {
        second[j] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0; 
    int index2 = 0; 
    mainArrayIndex = s; 

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

// Merge Sort
void mergeSort(int *arr, int s, int e) {
   // base case 
   if (s >= e) return;

   int mid = s + (e - s) / 2;

   // left part
   mergeSort(arr, s, mid);

   // right part
   mergeSort(arr, mid + 1, e);

   // merge both parts
   merge(arr, s, e);
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Bubble Sort Example
    int arr1[] = {5, 2, 9, 1, 6, 3};
    bubbleSort(arr1, n);
    cout << "Bubble Sorted: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    // Recursive Bubble Sort Example
    int arr2[] = {5, 2, 9, 1, 6, 3};
    bubbleSortRec(arr2, n);
    cout << "Recursive Bubble Sorted: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    // Merge Sort Example
    int arr3[] = {5, 2, 9, 1, 6, 3};
    mergeSort(arr3, 0, n - 1);
    cout << "Merge Sorted: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;

    return 0; 
}
