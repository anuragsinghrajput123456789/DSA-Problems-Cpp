#include <iostream>
#include <map>       // Required for using std::map
#include <string>    // For string values

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions ---" << endl;
    map<int, string> myMap; // Key: int, Value: string. Sorted by key.

    // Add elements using the [] operator (creates if not exists, updates if exists)
    myMap[1] = "babbar";
    myMap[2] = "love";
    myMap[13] = "kumar";
    myMap[2] = "singh"; // Updates the value for key 2 from "love" to "singh"

    // Add elements using insert()
    // insert returns a pair: {iterator to element, bool indicating insertion success}
    myMap.insert({5, "hero"});
    myMap.insert(make_pair(7, "coder")); // Another way to use insert

    cout << "Elements in myMap (sorted by key):" << endl;
    for (auto i : myMap) {
        cout << i.first << " --- " << i.second << endl;
    }
    // Expected output order (sorted by key):
    // 1 --- babbar
    // 2 --- singh
    // 5 --- hero
    // 7 --- coder
    // 13 --- kumar


    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myMap: " << myMap.size() << endl; // Expected: 5

    if (myMap.empty()) {
        cout << "myMap is empty." << endl;
    } else {
        cout << "myMap is NOT empty." << endl;
    }

    cout << "Max possible size for myMap: " << myMap.max_size() << endl;


    cout << "\n--- 3. Element Lookup Functions ---" << endl;

    // count() - returns 1 if key exists, 0 otherwise (since keys are unique)
    cout << "Count of key 2 in myMap: " << myMap.count(2) << endl;  // Expected: 1
    cout << "Count of key 100 in myMap: " << myMap.count(100) << endl; // Expected: 0

    // find() - returns an iterator to the element if key found, or myMap.end() if not
    auto it_find = myMap.find(13);
    if (it_find != myMap.end()) {
        cout << "Found key 13 in myMap: " << it_find->first << " --- " << it_find->second << endl;
    } else {
        cout << "Key 13 not found." << endl;
    }

    it_find = myMap.find(99);
    if (it_find != myMap.end()) {
        cout << "Found key 99 in myMap: " << it_find->first << " --- " << it_find->second << endl;
    } else {
        cout << "Key 99 not found." << endl;
    }

    // Accessing value by key (read-only)
    cout << "Value for key 1: " << myMap.at(1) << endl; // Throws out_of_range if key not found
    cout << "Value for key 5: " << myMap[5] << endl;   // Inserts default-constructed value if key not found


    cout << "\n--- 4. Modifiers (erase) ---" << endl;

    // erase() by key
    myMap.erase(2); // Removes the pair with key 2
    cout << "After erasing key 2, myMap elements:" << endl;
    for (auto i : myMap) {
        cout << i.first << " --- " << i.second << endl;
    }
    cout << "Size after erasing key 2: " << myMap.size() << endl; // Expected: 4

    // erase() by iterator
    auto it_erase = myMap.find(13); // Find key 13
    if (it_erase != myMap.end()) {
        myMap.erase(it_erase); // Erase the element pointed to by iterator
    }
    cout << "After erasing key 13 via iterator, myMap elements:" << endl;
    for (auto i : myMap) {
        cout << i.first << " --- " << i.second << endl;
    }
    cout << "Size after erasing key 13: " << myMap.size() << endl; // Expected: 3

    // erase() by range of iterators
    // Erase keys from 5 to (but not including) 7
    auto range_start = myMap.find(5);
    auto range_end = myMap.find(7); // Points to key 7
    if (range_start != myMap.end() && range_end != myMap.end()) {
        myMap.erase(range_start, range_end);
    }
    cout << "After erasing range (key 5), myMap elements:" << endl;
    for (auto i : myMap) {
        cout << i.first << " --- " << i.second << endl;
    }
    cout << "Size after erasing range: " << myMap.size() << endl; // Expected: 2 (1, 7)


    cout << "\n--- 5. Swap Function ---" << endl;
    map<int, string> map1;
    map1[10] = "ten";
    map1[20] = "twenty";

    map<int, string> map2;
    map2[30] = "thirty";
    map2[40] = "forty";
    map2[50] = "fifty";

    cout << "Before swap:" << endl;
    cout << "  Map1 elements: "; for(auto const& [key, val] : map1) cout << "(" << key << ":" << val << ") "; cout << ", size: " << map1.size() << endl;
    cout << "  Map2 elements: "; for(auto const& [key, val] : map2) cout << "(" << key << ":" << val << ") "; cout << ", size: " << map2.size() << endl;

    map1.swap(map2);

    cout << "After swap:" << endl;
    cout << "  Map1 elements: "; for(auto const& [key, val] : map1) cout << "(" << key << ":" << val << ") "; cout << ", size: " << map1.size() << endl; // Map1 now has elements of original Map2
    cout << "  Map2 elements: "; for(auto const& [key, val] : map2) cout << "(" << key << ":" << val << ") "; cout << ", size: " << map2.size() << endl; // Map2 now has elements of original Map1


    cout << "\n--- 6. Clearing the Map ---" << endl;
    myMap.clear(); // Removes all elements
    cout << "Size after clear(): " << myMap.size() << endl; // Expected: 0
    if (myMap.empty()) {
        cout << "myMap is now empty." << endl;
    }

    return 0;
}
