/// SEARCH IN A ROTATED SORTED ARRAY 
// by using pivot element in this....
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

int pivotElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s; // Return the index of the pivot element
}

int findPosition(int arr[], int n, int k) {
    int pivot = pivotElement(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarySearch(arr, pivot, n - 1, k);
    } else {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main() {
    int arr[] = {7, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2; // Example key to search for

    cout << "Pivot Index: " << pivotElement(arr, n) << endl;
    cout << "Position of " << key << ": " << findPosition(arr, n, key) << endl;

    return 0;
}