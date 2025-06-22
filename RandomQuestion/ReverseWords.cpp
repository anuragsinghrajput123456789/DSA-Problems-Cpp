//REVERESE WORDS IN A STRING USING VECTOR'S

#include <bits/stdc++.h>
using namespace std;

vector<char> reverse(vector<char> v) {
    int s = 0;
    int e = v.size() - 1;

    while (s <= e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

int main() {
    string name = "My name is love";
    vector<char> ans;
    vector<char> temp;

    for (int i = 0; i < name.size(); i++) {
        temp.push_back(name[i]);
        if (name[i] == ' ' || i == name.size() - 1) {
            vector<char> reversedTemp = reverse(temp);
            for (char c : reversedTemp) {
                ans.push_back(c);
            }
            temp.clear();
        }
    }

    for (char c : ans) {
        cout << "-" << c;
    }
    cout << endl;

    return 0;
}