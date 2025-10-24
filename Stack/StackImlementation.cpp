#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (top == size - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }

    int peek() {
        if (top >= 0)
            return arr[top];
        cout << "Stack is Empty!" << endl;
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st(5);

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    while (!st.isEmpty()) {
        cout << st.peek() << endl;
        st.pop();
    }

    return 0;
}
