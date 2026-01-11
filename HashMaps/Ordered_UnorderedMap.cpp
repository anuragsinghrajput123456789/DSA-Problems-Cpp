#include <bits/stdc++.h>
using namespace std;

int main() {

    /*
    QUESTION 1
    What is an ordered map?

    • Implemented using Red Black Tree
    • Stores keys in sorted order
    • Operations take O(log n) time
    */

    map<string, int> orderedMap;

    // Insertion methods
    orderedMap.insert(make_pair("babbar", 3));
    orderedMap.insert({"love", 2});
    orderedMap["mera"] = 1;

    // Updating value
    orderedMap["mera"] = 2;

    /*
    QUESTION 2
    How to access elements in map?
    */

    cout << "orderedMap[mera]: " << orderedMap["mera"] << endl;
    cout << "orderedMap.at(babbar): " << orderedMap.at("babbar") << endl;

    /*
    QUESTION 3
    Difference between [] and at()
    */

    // orderedMap["unknown"] creates a new entry with value 0
    cout << "orderedMap[unknown]: " << orderedMap["unknown"] << endl;

    // orderedMap.at("unknown2");  // throws exception

    /*
    QUESTION 4
    How to check size and presence?
    */

    cout << "Size of orderedMap: " << orderedMap.size() << endl;
    cout << "Is love present: " << orderedMap.count("love") << endl;
    cout << "Is bro present: " << orderedMap.count("bro") << endl;

    /*
    QUESTION 5
    How to iterate over ordered map?
    Output will be sorted by key.
    */

    cout << "\nOrdered Map Output\n";
    for (auto it = orderedMap.begin(); it != orderedMap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    /*
    QUESTION 6
    What is unordered_map?

    • Implemented using Hash Table
    • No ordering of keys
    • Average time O(1)
    */

    unordered_map<string, int> unorderedMap;

    unorderedMap["apple"] = 10;
    unorderedMap["banana"] = 5;
    unorderedMap["orange"] = 8;

    /*
    QUESTION 7
    Access and update in unordered_map
    */

    unorderedMap["banana"] = 20;
    cout << "\nunorderedMap[banana]: " << unorderedMap["banana"] << endl;

    /*
    QUESTION 8
    Iteration in unordered_map
    Output order is unpredictable.
    */

    cout << "\nUnordered Map Output\n";
    for (auto i : unorderedMap) {
        cout << i.first << " " << i.second << endl;
    }

    /*
    QUESTION 9
    Erase element
    */

    unorderedMap.erase("apple");
    cout << "\nAfter erasing apple\n";
    for (auto i : unorderedMap) {
        cout << i.first << " " << i.second << endl;
    }

    /*
    QUESTION 10
    When to use which?

    • Use map when sorted data is required
    • Use unordered_map for faster access
    */

    return 0;
}
