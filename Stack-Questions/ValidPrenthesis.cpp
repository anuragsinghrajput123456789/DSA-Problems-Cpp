#include<bits/stdc++.h>
using namespace std; 
bool isValidParenthesis(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // For closing bracket, compare with the top of the stack
            // Case if the stack is empty
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    // If the stack is empty at the end, all parentheses were matched
    return st.empty();
}

int main(){


    return 0; 
}