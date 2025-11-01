#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValidParenthesis(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If opening bracket ? push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket ? check top element
        else {
            if (st.empty()) return false; // No matching opening bracket
            char top = st.top();
            if (isMatching(top, ch)) {
                st.pop();
            } else {
                return false; // Mismatched pair
            }
        }
    }

    // If stack is empty ? all brackets matched
    return st.empty();
}
