#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std; 
// Added to remove std:: prefix

// The heapify function for a min-heap (0-based indexing)
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i; // Assume current node is the smallest
    int left = 2 * i + 1; // Calculate index of left child
    int right = 2 * i + 2; // Calculate index of right child
    
    // If left child exists and is smaller than the current smallest
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left; 
    }
    // If right child exists and is smaller than the current smallest
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right; 
    }
    
    // If the smallest is not the current node, swap them
    // and recursively heapify the affected subtree
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap from a given vector
vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array
    
    // Iterate from the last non-leaf node up to the root (index 0)
    // For 0-based indexing, the last non-leaf node is at (n/2 - 1)
    // The loop must go down to and include index 0
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Call heapify for each node
    }
    return arr; // Return the heapified array
}

int main(){


    return 0; 
}