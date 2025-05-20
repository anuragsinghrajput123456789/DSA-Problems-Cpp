#include <bits/stdc++.h>

using namespace std; 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (auto i : s)
    {
        char ch = i;

        // it means ya to ch '('
        if (ch == '(' || ch == '+' || ch == '/' || ch == '-' || ch == '*')
        {
            st.push(ch);
        }
        else
        {
            // ch ya to ')' ya to lowercase letter hoga
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '/' || top == '-' || top == '*')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true)
                {
                    return true;
                }
                st.pop(); //pop the '('
            }
        }
    }
    return false;
}

int main(){


    return 0; 
}