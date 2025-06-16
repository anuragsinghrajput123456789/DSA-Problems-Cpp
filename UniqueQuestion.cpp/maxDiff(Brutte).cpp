#include <iostream>  // For input/output operations (like cout)
#include <algorithm> // For max and min functions
#include <climits>   // For INT_MIN

using namespace std; // This line brings all names from the std namespace into the current scope

// Function to find the maximum difference arr[j] - arr[i] such that j > i
int maxDiff(int *arr, int n) {
    // Handle edge cases: If the array has 0 or 1 element, no difference can be found.
    if (n <= 1) {
        return 0;
    }

    // Initialize max_diff to the smallest possible integer value.
    // This correctly handles cases where the maximum difference might be negative
    // (e.g., a strictly decreasing array).
    int max_diff = INT_MIN;

    // Initialize min_element to the first element of the array.
    // This variable will keep track of the minimum element encountered so far
    // as we iterate through the array.
    int min_element = arr[0];

    // Iterate through the array starting from the second element.
    // We compare each element with the 'min_element' found before it.
    for (int i = 1; i < n; i++) {
        // Calculate the current difference: current element minus the minimum element seen so far.
        // Update 'max_diff' if this current difference is greater than the 'max_diff' found previously.
        max_diff = max(max_diff, arr[i] - min_element);

        // Update 'min_element' if the current element is smaller than the 'min_element' seen so far.
        // This ensures 'min_element' always holds the smallest value encountered up to the current index 'i'.
        min_element = min(min_element, arr[i]);
    }

    // If max_diff is still INT_MIN, it means there were no valid pairs (j > i and arr[j] > arr[i])
    // where a positive difference could be found. In such cases (e.g., a decreasing array),
    // a common expectation is to return 0. Adjust this based on specific problem requirements.
    if (max_diff == INT_MIN) {
        return 0; // Or return a specific error code, or the actual min_diff if negative diffs are allowed.
    }

    return max_diff;
}

int main() {
    int arr1[] = {1, 3, 4, 5, 6, 7, 8, 9};
    // Correctly calculate the size of a C-style array
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int ans1 = maxDiff(arr1, n1);
    cout << "Maximum difference for {1, 3, 4, 5, 6, 7, 8, 9}: " << ans1 << endl; // Expected: 8 (9 - 1)

    int arr2[] = {7, 9, 5, 6, 3, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int ans2 = maxDiff(arr2, n2);
    cout << "Maximum difference for {7, 9, 5, 6, 3, 2}: " << ans2 << endl; // Expected: 2 (9 - 7 or 6 - 5, whichever is max)

    int arr3[] = {10, 8, 7, 6, 5}; // Decreasing array
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int ans3 = maxDiff(arr3, n3);
    cout << "Maximum difference for {10, 8, 7, 6, 5}: " << ans3 << endl; // Expected: 0 (no 'buy low, sell high' possible)

    int arr4[] = {1, 0, -1}; // Array with negative numbers
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int ans4 = maxDiff(arr4, n4);
    cout << "Maximum difference for {1, 0, -1}: " << ans4 << endl; // Expected: 0

    return 0;
}