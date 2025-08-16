#include <iostream>
#include <deque>     // Required for using std::deque
#include <numeric>   // For iota
#include <algorithm> // For algorithms like for_each

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions ---" << endl;
    deque<int> myDeque;

    // Add elements using push_back() and push_front()
    myDeque.push_back(10);
    myDeque.push_front(5);
    myDeque.push_back(20);
    myDeque.push_front(0);
    myDeque.push_back(30);

    cout << "Initial myDeque elements (front to back): ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 0 5 10 20 30

    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myDeque: " << myDeque.size() << endl;
    // Deque does not have a 'capacity()' function like vector, as its memory management is different.
    // It manages memory in chunks, so there isn't a single contiguous block's capacity to report.

    if (myDeque.empty()) {
        cout << "myDeque is empty." << endl;
    } else {
        cout << "myDeque is NOT empty." << endl;
    }

    cout << "Max possible size for myDeque: " << myDeque.max_size() << endl;


    cout << "\n--- 3. Element Access Functions ---" << endl;
    try {
        cout << "Element at index 2 (using at()): " << myDeque.at(2) << endl; // Should be 10
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Element at index 0 (using []): " << myDeque[0] << endl; // Should be 0
    cout << "First element (front()): " << myDeque.front() << endl; // Should be 0
    cout << "Last element (back()): " << myDeque.back() << endl;   // Should be 30


    cout << "\n--- 4. Modifiers ---" << endl;

    // pop_front() and pop_back()
    myDeque.pop_front(); // Removes 0
    myDeque.pop_back();  // Removes 30
    cout << "After pop_front() and pop_back(), myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 5 10 20

    // insert() - inserts elements
    // Insert 15 at the beginning (before myDeque.begin())
    myDeque.insert(myDeque.begin(), 15);
    // Insert 3 copies of 99 at index 2 (myDeque.begin() + 2)
    myDeque.insert(myDeque.begin() + 2, 3, 99);
    cout << "After inserts, myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 15 5 99 99 99 10 20

    // erase() - removes elements
    // Erase the element at index 1 (myDeque.begin() + 1)
    myDeque.erase(myDeque.begin() + 1); // Removes 5
    cout << "After erase at index 1, myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 15 99 99 99 10 20

    // erase a range
    myDeque.erase(myDeque.begin() + 1, myDeque.begin() + 4); // Removes 3 99s
    cout << "After erasing a range (3 elements), myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 15 10 20


    // resize() - changes the number of elements
    myDeque.resize(2); // Shrink to 2 elements. Elements beyond index 1 are removed.
    cout << "After resize(2), myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 15 10

    myDeque.resize(5, 77); // Grow to 5 elements, fill new elements with 77
    cout << "After resize(5, 77), myDeque elements: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl; // Expected: 15 10 77 77 77


    // swap() - exchanges contents with another deque
    deque<int> anotherDeque(3);
    iota(anotherDeque.begin(), anotherDeque.end(), 100); // Fills with 100, 101, 102

    cout << "Before swap:" << endl;
    cout << "  myDeque: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherDeque: ";
    for (int x : anotherDeque) {
        cout << x << " ";
    }
    cout << endl;

    myDeque.swap(anotherDeque);

    cout << "After swap:" << endl;
    cout << "  myDeque: ";
    for (int x : myDeque) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherDeque: ";
    for (int x : anotherDeque) {
        cout << x << " ";
    }
    cout << endl;


    cout << "\n--- 5. Iterators ---" << endl;
    cout << "Elements of myDeque (using begin()/end()): ";
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Elements of myDeque (using rbegin()/rend() - reverse): ";
    for (auto it = myDeque.rbegin(); it != myDeque.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    cout << "\n--- 6. Clearing the Deque ---" << endl;
    myDeque.clear(); // Removes all elements
    cout << "Size after clear(): " << myDeque.size() << endl;
    if (myDeque.empty()) {
        cout << "myDeque is now empty." << endl;
    }

    // Deque does not have shrink_to_fit() as its memory model is different from vector.

    return 0;
}
