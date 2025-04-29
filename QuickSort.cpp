//QUICK SORT HAI BHAI...

#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[s];
    int i = s;
    int j = e;

    while (i < j) {
        // Find element on left greater than pivot
        while (arr[i] <= pivot && i < e) {
            i++;
        }

        // Find element on right smaller than pivot
        while (arr[j] > pivot && j > s) {
            j--;
        }

        // Swap if i and j haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct sorted position
    swap(arr[s], arr[j]);
    return j;
}

void quick_sort(int *arr, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }

    // Partition karenge
    int p = partition(arr, s, e);

    // Left part sort karenge
    quick_sort(arr, s, p - 1);

    // Right part sort karenge
    quick_sort(arr, p + 1, e);
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}