#include<bits/stdc++.h>
// Using specific headers is better practice than <bits/stdc++.h>
using namespace std;


int firstOcc(int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1; // Keep searching in the left part
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        // BUG FIX: Removed the redundant mid calculation from here.
    }
    return ans;
}

/**
 * @brief Finds the last (rightmost) occurrence of a key in a sorted array.
 */
int lastOcc(int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1; // Keep searching in the right part
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        // BUG FIX: Removed the redundant mid calculation from here.
    }
    return ans;
}

int main() {
    // Using an array with duplicates to better show the functions' purpose
    int arr[] = {1, 3, 5, 5, 5, 5, 9, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    cout << "Array: {1, 3, 5, 5, 5, 5, 9, 11, 15}" << endl;
    cout << "Finding first and last occurrences of: " << key << endl;

    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);

    cout << "First occurrence is at index: " << first << endl;
    cout << "Last occurrence is at index:  " << last << endl;

    if (first != -1) {
        cout << "Total occurrences: " << (last - first + 1) << endl;
    }

    return 0;
}