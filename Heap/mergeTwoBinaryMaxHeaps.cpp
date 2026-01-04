#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // Heapify function - 0-based indexing (very important!)
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;          // current root
        int left  = 2 * i + 1;    // left child
        int right = 2 * i + 2;    // right child

        // Compare with left child
        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }

        // Compare with right child
        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            // Recursively heapify the affected subtree
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Step 1: Merge both arrays
        vector<int> ans = a;
        ans.insert(ans.end(), b.begin(), b.end());

        int size = ans.size();

        // Step 2: Build max-heap from the merged array
        // Start from the last non-leaf node → (size/2 - 1)
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(ans, size, i);
        }

        return ans;
    }
};

int main(){


    return 0; 
}