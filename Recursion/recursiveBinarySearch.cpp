#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search (returns index or -1)
int binarySearch(int *arr, int n, int key) {
    int s = 0; 
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            // Search right half
            s = mid + 1;
        } else {
            // Search left half
            e = mid - 1; 
        }
    }
    return -1; 
}

// Recursive Binary Search (returns true/false)
bool recursiveBinarySearch(int *arr, int s, int e, int key) {
    // Base case: Not found
    if (s > e) return false;

    int mid = s + (e - s) / 2;

    // Base case: Found
    if (arr[mid] == key) return true;

    if (arr[mid] < key) {
        // Search right half
        return recursiveBinarySearch(arr, mid + 1, e, key);
    } else {
        // Search left half
        return recursiveBinarySearch(arr, s, mid - 1, key);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort array before applying binary search
    sort(arr, arr + n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int key = 6;

    // Iterative Search
    int idx = binarySearch(arr, n, key);
    if (idx != -1)
        cout << "Iterative: Found " << key << " at index " << idx << endl;
    else
        cout << "Iterative: Key not foundre" << endl;

    // Recursive Search
    if (recursiveBinarySearch(arr, 0, n - 1, key))
        cout << "Recursive: Found " << key << endl;
    else
        cout << "Recursive: Key not found" << endl;

    return 0;
}
