#include <bits/stdc++.h>
using namespace std;

// Helper function: 0-based max-heapify
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to merge two max-heaps
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Step 1: Merge both arrays
    vector<int> ans = arr1;                    // copy first heap
    ans.insert(ans.end(), arr2.begin(), arr2.end());  // append second heap

    int totalSize = ans.size();

    // Step 2: Build max-heap on the merged array
    // Start from last non-leaf node
    for (int i = totalSize / 2 - 1; i >= 0; i--) {
        heapify(ans, totalSize, i);
    }

    return ans;
}