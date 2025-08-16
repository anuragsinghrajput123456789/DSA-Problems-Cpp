#include <iostream>
#include <list>      // Required for using std::list
#include <numeric>   // For iota (useful for generating sequences)
#include <algorithm> // For algorithms (though list has many member functions for its operations)

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions ---" << endl;
    list<int> myList;

    // Add elements using push_back() and push_front()
    myList.push_back(10);
    myList.push_front(5);
    myList.push_back(20);
    myList.push_front(0);
    myList.push_back(30);

    cout << "Initial myList elements (front to back): ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 0 5 10 20 30

    // --- Fixing the copy constructor ---
    // If you copy a list, copy it AFTER it has elements
    list<int> copiedList(myList); // Now 'copiedList' will contain 0 5 10 20 30
    cout << "Copied list elements: ";
    for (int x : copiedList) {
        cout << x << " ";
    }
    cout << endl;


    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myList: " << myList.size() << endl;
    // List does not have 'capacity()' or 'reserve()' as elements are not contiguous.

    if (myList.empty()) {
        cout << "myList is empty." << endl;
    } else {
        cout << "myList is NOT empty." << endl;
    }

    cout << "Max possible size for myList: " << myList.max_size() << endl;


    cout << "\n--- 3. Element Access Functions ---" << endl;
    // Lists do NOT support random access (no at() or [] operator)
    // Accessing first and last elements
    cout << "First element (front()): " << myList.front() << endl; // Should be 0
    cout << "Last element (back()): " << myList.back() << endl;   // Should be 30


    cout << "\n--- 4. Modifiers ---" << endl;

    // pop_front() and pop_back()
    myList.pop_front(); // Removes 0
    myList.pop_back();  // Removes 30
    cout << "After pop_front() and pop_back(), myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 10 20

    // insert() - inserts elements
    // Get an iterator to the second element (10)
    auto it = myList.begin();
    advance(it, 1); // Move iterator to the 2nd element (value 10)

    // Insert 15 before the current position of 'it' (before 10)
    myList.insert(it, 15);
    // Insert 3 copies of 99 before the current position of 'it' (still before original 10)
    myList.insert(it, 3, 99);
    cout << "After inserts, myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 15 99 99 99 10 20

    // erase() - removes elements
    // Erase the element pointed to by an iterator
    // Move 'it' to the element '15' (now at index 1)
    it = myList.begin();
    advance(it, 1);
    myList.erase(it); // Removes 15
    cout << "After erase, myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 99 99 99 10 20

    // erase a range
    // Erase the three 99s
    auto start_erase = myList.begin();
    advance(start_erase, 1); // points to first 99
    auto end_erase = start_erase;
    advance(end_erase, 3);   // points past the last 99
    myList.erase(start_erase, end_erase);
    cout << "After erasing a range (3 elements), myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 10 20

    // remove() - removes all occurrences of a specific value
    myList.push_back(10); // Add another 10
    myList.push_front(5); // Add another 5
    cout << "myList before remove(): ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 5 10 20 10

    myList.remove(10); // Removes all instances of 10
    cout << "After remove(10), myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 5 20


    // resize() - changes the number of elements
    myList.resize(2); // Shrink to 2 elements.
    cout << "After resize(2), myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 5

    myList.resize(5, 77); // Grow to 5 elements, fill new elements with 77
    cout << "After resize(5, 77), myList elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 5 77 77 77


    // swap() - exchanges contents with another list
    list<int> anotherList;
    anotherList.push_back(100);
    anotherList.push_back(101);
    anotherList.push_back(102);

    cout << "Before swap:" << endl;
    cout << "  myList: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherList: ";
    for (int x : anotherList) {
        cout << x << " ";
    }
    cout << endl;

    myList.swap(anotherList);

    cout << "After swap:" << endl;
    cout << "  myList: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherList: ";
    for (int x : anotherList) {
        cout << x << " ";
    }
    cout << endl;


    cout << "\n--- 5. Special List Modifiers (splice, sort, unique, reverse, merge) ---" << endl;

    // splice() - transfers elements from one list to another
    list<int> sourceList = {1, 2, 3};
    list<int> destList = {100, 200, 300};
    cout << "Before splice:" << endl;
    cout << "  sourceList: ";
    for (int x : sourceList) cout << x << " "; cout << endl;
    cout << "  destList: ";
    for (int x : destList) cout << x << " "; cout << endl;

    // Move all elements from sourceList to the beginning of destList
    destList.splice(destList.begin(), sourceList);
    cout << "After splice (all from sourceList to destList.begin()):" << endl;
    cout << "  sourceList: ";
    for (int x : sourceList) cout << x << " "; cout << endl; // Empty
    cout << "  destList: ";
    for (int x : destList) cout << x << " "; cout << endl;   // 1 2 3 100 200 300

    // sort()
    list<int> unsortedList = {50, 10, 40, 20, 30};
    cout << "Unsorted list: ";
    for (int x : unsortedList) cout << x << " "; cout << endl;
    unsortedList.sort();
    cout << "Sorted list: ";
    for (int x : unsortedList) cout << x << " "; cout << endl;

    // unique() - removes consecutive duplicate elements
    list<int> dupeList = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    cout << "List with duplicates: ";
    for (int x : dupeList) cout << x << " "; cout << endl;
    dupeList.unique();
    cout << "List after unique(): ";
    for (int x : dupeList) cout << x << " "; cout << endl; // Expected: 1 2 3 4 5

    // reverse()
    list<int> revList = {1, 2, 3, 4, 5};
    cout << "Original list for reverse: ";
    for (int x : revList) cout << x << " "; cout << endl;
    revList.reverse();
    cout << "Reversed list: ";
    for (int x : revList) cout << x << " "; cout << endl; // Expected: 5 4 3 2 1

    // merge() - merges two sorted lists
    list<int> listA = {1, 3, 5};
    list<int> listB = {2, 4, 6};
    cout << "List A: "; for (int x : listA) cout << x << " "; cout << endl;
    cout << "List B: "; for (int x : listB) cout << x << " "; cout << endl;
    listA.merge(listB); // listB becomes empty, its elements are moved to listA
    cout << "After merge, List A: "; for (int x : listA) cout << x << " "; cout << endl; // Expected: 1 2 3 4 5 6
    cout << "After merge, List B: "; for (int x : listB) cout << x << " "; cout << endl; // Empty


    cout << "\n--- 6. Clearing the List ---" << endl;
    myList.clear(); // Removes all elements
    cout << "Size after clear(): " << myList.size() << endl;
    if (myList.empty()) {
        cout << "myList is now empty." << endl;
    }

    return 0;
}
