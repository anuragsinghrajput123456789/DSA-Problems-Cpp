#include <bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int x : arr) {
        if (left.empty() || x <= left.top()) left.push(x);
        else right.push(x);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }

        if (left.size() == right.size())
            ans.push_back((left.top() + right.top()) / 2);
        else
            ans.push_back(left.size() > right.size() ? left.top() : right.top());
    }
    return ans;
}

int main(){


    return 0; 
}