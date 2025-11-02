#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // push if operator or '('
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if (ch == ')') {
            bool isRedundant = true;

            // check elements inside current ()
            while (!st.empty() && st.top() != '(') {
                char top = st.top();

                if (top == '+' || top == '-' || top == '*' || top == '/')
                    isRedundant = false;

                st.pop();
            }

            // pop the opening bracket
            if (!st.empty()) st.pop();

            // if no operator found ? redundant
            if (isRedundant)
                return true;
        }
    }

    return false;
}
int main(){



    

    return 0; 
}