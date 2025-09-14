#include <bits/stdc++.h>
using namespace std;

// Recursive bubble sort helper (like inner loop)
void bubbleSortRecHelper(int *arr, int n, int j) {
    // base case: finished one pass
    if (j == n - 1) return;

    // compare adjacent
    if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
    }

    // move to next element
    bubbleSortRecHelper(arr, n, j + 1);
}

// Main recursive bubble sort (like outer loop)
void bubbleSortRec(int *arr, int n) {
    // base case: array size 1 → already sorted
    if (n == 1) return;

    // one full pass (bubble largest to end)
    bubbleSortRecHelper(arr, n, 0);

    // recursive call for remaining array
    bubbleSortRec(arr, n - 1);
}

int main() {
    int arr[] = {7, 9, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRec(arr, n);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
