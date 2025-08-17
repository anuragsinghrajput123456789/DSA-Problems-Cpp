#include <iostream>
#include <set>       // Required for using std::set
#include <string>    // For string elements, if needed

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions (insert) ---" << endl;
    set<int> mySet; // Elements will be stored in ascending order and unique

    // Add elements using insert()
    mySet.insert(3);
    mySet.insert(32);
    mySet.insert(34);
    mySet.insert(32); // Duplicate, will not be inserted
    mySet.insert(31);
    mySet.insert(3);  // Duplicate, will not be inserted
    mySet.insert(33);

    cout << "Elements inserted: 3, 32, 34, 31, 33 (duplicates ignored, order sorted)" << endl;
    cout << "mySet elements (sorted): ";
    // Sets provide iterators, so range-based for loop works
    for (int x : mySet) {
        cout << x << " ";
    }
    cout << endl; // Expected: 3 31 32 33 34


    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of mySet: " << mySet.size() << endl; // Expected: 5

    if (mySet.empty()) {
        cout << "mySet is empty." << endl;
    } else {
        cout << "mySet is NOT empty." << endl;
    }

    cout << "Max possible size for mySet: " << mySet.max_size() << endl;


    cout << "\n--- 3. Element Lookup Functions ---" << endl;

    // count() - returns 1 if element exists, 0 otherwise (since elements are unique)
    cout << "Count of 32 in mySet: " << mySet.count(32) << endl; // Expected: 1
    cout << "Count of 99 in mySet: " << mySet.count(99) << endl; // Expected: 0

    // find() - returns an iterator to the element if found, or mySet.end() if not
    auto it_find = mySet.find(31);
    if (it_find != mySet.end()) {
        cout << "Found 31 in mySet: " << *it_find << endl;
    } else {
        cout << "31 not found." << endl;
    }

    it_find = mySet.find(100);
    if (it_find != mySet.end()) {
        cout << "Found 100 in mySet: " << *it_find << endl;
    } else {
        cout << "100 not found." << endl;
    }


    cout << "\n--- 4. Modifiers (erase) ---" << endl;

    // erase() by value
    mySet.erase(32); // Removes element 32
    cout << "After erasing 32, mySet elements: ";
    for (int x : mySet) {
        cout << x << " ";
    }
    cout << endl; // Expected: 3 31 33 34
    cout << "Size after erasing 32: " << mySet.size() << endl; // Expected: 4

    // erase() by iterator
    auto it_erase = mySet.find(3); // Find 3
    if (it_erase != mySet.end()) {
        mySet.erase(it_erase); // Erase element pointed to by iterator
    }
    cout << "After erasing 3 via iterator, mySet elements: ";
    for (int x : mySet) {
        cout << x << " ";
    }
    cout << endl; // Expected: 31 33 34
    cout << "Size after erasing 3: " << mySet.size() << endl; // Expected: 3


    cout << "\n--- 5. Swap Function ---" << endl;
    set<int> set1;
    set1.insert(10);
    set1.insert(20);

    set<int> set2;
    set2.insert(30);
    set2.insert(40);
    set2.insert(50);

    cout << "Before swap:" << endl;
    cout << "  Set1 elements: "; for(int x : set1) cout << x << " "; cout << ", size: " << set1.size() << endl;
    cout << "  Set2 elements: "; for(int x : set2) cout << x << " "; cout << ", size: " << set2.size() << endl;

    set1.swap(set2);

    cout << "After swap:" << endl;
    cout << "  Set1 elements: "; for(int x : set1) cout << x << " "; cout << ", size: " << set1.size() << endl; // Set1 now has elements of original Set2
    cout << "  Set2 elements: "; for(int x : set2) cout << x << " "; cout << ", size: " << set2.size() << endl; // Set2 now has elements of original Set1


    cout << "\n--- 6. Clearing the Set ---" << endl;
    mySet.clear(); // Removes all elements
    cout << "Size after clear(): " << mySet.size() << endl; // Expected: 0
    if (mySet.empty()) {
        cout << "mySet is now empty." << endl;
    }

    return 0;
}
