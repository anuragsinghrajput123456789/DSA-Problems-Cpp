#include <iostream>  // For input/output operations (cout, endl)
#include <vector>    // For std::vector
#include <algorithm> // Essential for most algorithms (e.g., sort, binary_search, find)
#include <numeric>   // For std::accumulate (summing elements)
#include <functional> // For std::plus, if explicitly needed with accumulate

using namespace std; // Use the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Basic Vector Setup ---" << endl;
    vector<int> v = {1, 5, 8, 2, 9, 4, 3, 7, 6, 5};
    cout << "Original vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // --- 2. Sorting and Searching Algorithms ---
    cout << "\n--- 2. Sorting and Searching Algorithms ---" << endl;

    // sort(): Sorts elements in ascending order
    sort(v.begin(), v.end());
    cout << "Vector after sort(): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl; // Expected: 1 2 3 4 5 5 6 7 8 9

    // binary_search(): Checks if an element exists in a SORTED range
    // Returns true if found, false otherwise
    cout << "Is 3 present in vector (binary_search)? " << (binary_search(v.begin(), v.end(), 3) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Is 10 present in vector (binary_search)? " << (binary_search(v.begin(), v.end(), 10) ? "Yes" : "No") << endl; // Expected: No

    // find(): Searches for the first occurrence of a value in a range
    // Returns an iterator to the element if found, or v.end() if not found
    auto it_find = find(v.begin(), v.end(), 5);
    if (it_find != v.end()) {
        cout << "First 5 found at index: " << distance(v.begin(), it_find) << endl; // Expected: index 4
    } else {
        cout << "5 not found." << endl;
    }

    // count(): Counts occurrences of a value in a range
    cout << "Number of 5s in vector: " << count(v.begin(), v.end(), 5) << endl; // Expected: 2


    // --- 3. Min/Max and Reordering Algorithms ---
    cout << "\n--- 3. Min/Max and Reordering Algorithms ---" << endl;

    // min_element(): Returns an iterator to the smallest element
    cout << "Smallest element (min_element): " << *min_element(v.begin(), v.end()) << endl; // Expected: 1

    // max_element(): Returns an iterator to the largest element
    cout << "Largest element (max_element): " << *max_element(v.begin(), v.end()) << endl; // Expected: 9

    // reverse(): Reverses the order of elements in a range
    reverse(v.begin(), v.end());
    cout << "Vector after reverse(): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl; // Expected: 9 8 7 6 5 5 4 3 2 1

    // rotate(): Rotates elements in a range
    // Moves the element at 'middle' to the beginning, and shifts others accordingly
    // Example: Rotate so that '5' (the first 5 after reverse) becomes the new first element
    rotate(v.begin(), v.begin() + 4, v.end()); // rotate(start, new_start, end)
    cout << "Vector after rotate (shifted elements starting from index 4 to front): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 5 4 3 2 1 9 8 7 6 (original: 9 8 7 6 5 5 4 3 2 1, new start at 5)


    // --- 4. Modifying and Transforming Algorithms ---
    cout << "\n--- 4. Modifying and Transforming Algorithms ---" << endl;

    // unique(): Removes consecutive duplicate elements (leaves one of each unique element).
    // Note: It only works on *consecutive* duplicates, so sorting is often needed first.
    // It doesn't actually resize the vector, but returns an iterator to the new 'end'
    vector<int> dupe_vec = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    cout << "Original dupe_vec: ";
    for (int x : dupe_vec) cout << x << " "; cout << endl;
    auto last_unique = unique(dupe_vec.begin(), dupe_vec.end());
    dupe_vec.erase(last_unique, dupe_vec.end()); // Erase the 'removed' duplicates
    cout << "dupe_vec after unique() and erase: ";
    for (int x : dupe_vec) {
        cout << x << " ";
    }
    cout << endl; // Expected: 1 2 3 4 5

    // transform(): Applies a function to each element in a range and stores the result
    // in another (or the same) range.
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> squared_numbers(numbers.size());
    transform(numbers.begin(), numbers.end(), squared_numbers.begin(), [](int x){ return x * x; });
    cout << "Original numbers: "; for(int x : numbers) cout << x << " "; cout << endl;
    cout << "Squared numbers: "; for(int x : squared_numbers) cout << x << " "; cout << endl;


    // --- 5. Numeric Algorithms ---
    cout << "\n--- 5. Numeric Algorithms ---" << endl;

    // accumulate(): Computes the sum of elements in a range
    // Requires <numeric> header
    vector<int> nums_to_sum = {1, 2, 3, 4, 5};
    int sum = accumulate(nums_to_sum.begin(), nums_to_sum.end(), 0); // 0 is initial sum
    cout << "Sum of elements (accumulate): " << sum << endl; // Expected: 15


    // --- 6. Bound-Finding Algorithms (for sorted ranges) ---
    cout << "\n--- 6. Bound-Finding Algorithms (for sorted ranges) ---" << endl;
    vector<int> sorted_v = {10, 20, 30, 30, 30, 40, 50};
    cout << "Sorted vector for bounds: ";
    for (int x : sorted_v) {
        cout << x << " ";
    }
    cout << endl;

    // lower_bound(): Returns an iterator to the first element not less than (>=) value
    auto lb = lower_bound(sorted_v.begin(), sorted_v.end(), 30);
    cout << "lower_bound for 30 at index: " << distance(sorted_v.begin(), lb) << endl; // Expected: 2 (points to the first 30)

    // upper_bound(): Returns an iterator to the first element greater than (>) value
    auto ub = upper_bound(sorted_v.begin(), sorted_v.end(), 30);
    cout << "upper_bound for 30 at index: " << distance(sorted_v.begin(), ub) << endl; // Expected: 5 (points after the last 30)


    // --- 7. Element Removal (by value) ---
    cout << "\n--- 7. Element Removal (by value) ---" << endl;
    vector<int> remove_vec = {1, 5, 2, 5, 3, 5, 4};
    cout << "Vector before remove(): ";
    for (int x : remove_vec) cout << x << " "; cout << endl;

    // remove(): Moves elements *not* matching the value to the beginning of the range.
    // It doesn't actually erase elements from the vector or change its size.
    // It returns an iterator to the new end of the valid range.
    auto new_end = remove(remove_vec.begin(), remove_vec.end(), 5);
    cout << "Vector after remove(5) (elements moved): ";
    for (int x : remove_vec) cout << x << " "; cout << endl; // Shows original size, but 5s are at the end

    remove_vec.erase(new_end, remove_vec.end()); // Physically removes the elements
    cout << "Vector after remove(5) and erase(): ";
    for (int x : remove_vec) cout << x << " "; cout << endl; // Expected: 1 2 3 4


    return 0;
}
