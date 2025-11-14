#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s; 
    int mini;

public:

    // Push operation
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if (data < mini) {
                int val = 2 * data - mini;  // encoded value
                s.push(val);
                mini = data;                // update new minimum
            } else {
                s.push(data);
            }
        }
    }

    // Pop operation
    int pop() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr >= mini) {
            return curr;  // normal value
        }
        else {
            // encoded value found
            int originalMin = mini;
            int previousMin = 2 * mini - curr;
            mini = previousMin;
            return originalMin;
        }
    }

    // Top element function
    int top() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        if (curr < mini) {
            return mini;  // means this is encoded value
        }
        else {
            return curr;
        }
    }

    // Get minimum
    int getMin() {
        if (s.empty()) {
            return -1;
        }
        return mini;
    }
};


int main(){



    return 0; 
}