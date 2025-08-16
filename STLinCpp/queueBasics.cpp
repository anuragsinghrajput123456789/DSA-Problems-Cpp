
// QUEUE IN STL C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> q;

    q.push("anurag");
    q.push("singh");
    q.push("rajput");

    // Printing elements using while loop
    cout << "Elements in queue:" << endl;
    queue<string> temp = q; // use a copy so original queue stays unchanged
    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }

    cout << "First Element: " << q.front() << endl;
    cout << "Size of the queue: " << q.size() << endl;

    return 0;
}
