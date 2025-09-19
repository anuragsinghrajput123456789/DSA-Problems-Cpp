#include <bits/stdc++.h>
using namespace std;

int partitionElement(int *arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;

    // Count elements smaller than pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    // Place pivot in correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Left and right adjustment
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    // base case
    if (s >= e) return;

    int p = partitionElement(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {2, 1, 3, 8, 5, 2, 6, 4, 3, 2, 1, 3, 1, 5, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // ✅ fixed size calc

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
