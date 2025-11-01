#include <bits/stdc++.h>
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    stack<int> temp;

    // Step 1: Pop all elements into temp
    while (!myStack.empty()) {
        temp.push(myStack.top());
        myStack.pop();
    }

    // Step 2: Push new element at the bottom
    myStack.push(x);

    // Step 3: Push everything back to original stack
    while (!temp.empty()) {
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    st = pushAtBottom(st, 0);

    cout << "Stack from top to bottom: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
