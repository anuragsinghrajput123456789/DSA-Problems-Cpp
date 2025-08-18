#include <bits/stdc++.h>
using namespace std; 

// Merge two sorted arrays into arr3
void merge(int arr1[], int m, int arr2[], int n, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < m) {
        arr3[k++] = arr1[i++];
    }

    while (j < n) {
        arr3[k++] = arr2[j++];
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};   // Sorted
    int arr2[] = {1, 1, 2, 3, 9};      // Sorted
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[m + n] = {0};

    merge(arr1, m, arr2, n, arr3);

    cout << "Merged Sorted Array: ";
    print(arr3, m + n);

    return 0;
}
