
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
    Node* top;            // Stack owns the top pointer

public:
    Stack() : top(nullptr) {}   // initialize an empty stack

    // Push: insert at front (top)
    void push(int data) {
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        cout << data << " inserted into stack\n";
    }

    // Pop: remove and return top element; on empty stack return -1 (or throw)
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow (nothing to pop)\n";
            return -1;
        }
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        cout << val << " popped from stack\n";
        return val;
    }

    // Peek: view top without removing
    int peek() const {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Print stack from top to bottom, without modifying it
    void print() const {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        Node* cur = top;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // Check empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Destructor to free any remaining nodes
    ~Stack() {
        while (top) {
            Node* tmp = top;
            top = top->next;
            delete tmp;
        }
    }
};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);

    st.print();                 // expect: 33 22 11 (top -> bottom)
    cout << "Current top: " << st.peek() << "\n"; // expect 33

    st.pop();                   // pops 33
    st.print();                 // expect: 22 11

    st.pop();                   // pops 22
    st.pop();                   // pops 11
    st.pop();                   // underflow

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes\n" : "No\n");

    return 0;
}
