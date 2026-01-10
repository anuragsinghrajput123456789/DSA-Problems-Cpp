#include <bits/stdc++.h>
using namespace std;

int main() {

    // creation
    unordered_map<string, int> m;

    // insertion methods
    m.insert(make_pair("babbar", 3));
    m.insert({"Love", 2});
    m["mera"] = 1;

    // overwrite value
    m["mera"] = 2;

    // access
    cout << "mera value: " << m["mera"] << endl;

    // safe access using at()
    if (m.find("babbar") != m.end()) {
        cout << "babbar value: " << m.at("babbar") << endl;
    }

    // size
    cout << "size: " << m.size() << endl;

    // presence check
    cout << "Love exists: " << m.count("Love") << endl;
    cout << "love exists: " << m.count("love") << endl;

    // erase
    m.erase("Love");
    cout << "size after erase: " << m.size() << endl;

    // iterate and print
    cout << "All key-value pairs:" << endl;
    for (auto &it : m) {
        cout << it.first << " -> " << it.second << endl;
    }

    // find
    auto it = m.find("mera");
    if (it != m.end()) {
        cout << "Found mera with value: " << it->second << endl;
    }

    // clear map
    m.clear();
    cout << "size after clear: " << m.size() << endl;

    return 0;
}
