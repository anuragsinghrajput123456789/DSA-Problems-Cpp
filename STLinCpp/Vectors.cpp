#include <iostream>
#include <vector>
#include <numeric>   // For iota
#include <algorithm> // For algorithms like for_each

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions ---" << endl;
    vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(50);

    cout << "Initial myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myVector: " << myVector.size() << endl;
    cout << "Current capacity of myVector: " << myVector.capacity() << endl;

    if (myVector.empty()) {
        cout << "myVector is empty." << endl;
    } else {
        cout << "myVector is NOT empty." << endl;
    }

    myVector.reserve(100);
    cout << "Capacity after reserve(100): " << myVector.capacity() << endl;

    cout << "\n--- 3. Element Access Functions ---" << endl;
    try {
        cout << "Element at index 2 (using at()): " << myVector.at(2) << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Element at index 0 (using []): " << myVector[0] << endl;
    cout << "First element (front()): " << myVector.front() << endl;
    cout << "Last element (back()): " << myVector.back() << endl;

    int* dataPtr = myVector.data();
    cout << "Element at index 1 via data() pointer: " << *(dataPtr + 1) << endl;

    cout << "\n--- 4. Modifiers ---" << endl;

    myVector.pop_back();
    cout << "After pop_back(), myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    myVector.insert(myVector.begin(), 15);
    myVector.insert(myVector.begin() + 2, 3, 99);
    cout << "After inserts, myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    myVector.erase(myVector.begin() + 1);
    cout << "After erase at index 1, myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    myVector.resize(5);
    cout << "After resize(5), myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    myVector.resize(8, 77);
    cout << "After resize(8, 77), myVector elements: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> anotherVector(3);
    iota(anotherVector.begin(), anotherVector.end(), 100);

    cout << "Before swap:" << endl;
    cout << "  myVector: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherVector: ";
    for (int x : anotherVector) {
        cout << x << " ";
    }
    cout << endl;

    myVector.swap(anotherVector);

    cout << "After swap:" << endl;
    cout << "  myVector: ";
    for (int x : myVector) {
        cout << x << " ";
    }
    cout << endl;
    cout << "  anotherVector: ";
    for (int x : anotherVector) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n--- 5. Iterators ---" << endl;
    cout << "Elements of myVector (using begin()/end()): ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Elements of myVector (using rbegin()/rend() - reverse): ";
    for (auto it = myVector.rbegin(); it != myVector.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n--- 6. Clearing the Vector ---" << endl;
    myVector.clear();
    cout << "Size after clear(): " << myVector.size() << endl;
    cout << "Capacity after clear(): " << myVector.capacity() << endl;
    if (myVector.empty()) {
        cout << "myVector is now empty." << endl;
    }

    myVector.shrink_to_fit();
    cout << "Capacity after shrink_to_fit(): " << myVector.capacity() << endl;

    return 0;
}
