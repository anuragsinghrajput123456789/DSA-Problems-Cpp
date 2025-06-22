
#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '/' || ch == '*' || ch == '-') {
            st.push(ch); // Push opening bracket or operator onto the stack
        } else if (ch == ')') {
            bool isRedundant = true;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '/' || top == '*' || top == '-') {
                    isRedundant = false; // Found an operator, not redundant
                }
                st.pop();
            }

            // Pop the opening bracket '('
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }

            if (isRedundant) {
                return true; // Redundant brackets found
            }
        }
    }
    return false; // No redundant brackets
}
