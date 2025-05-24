#include <iostream> // Required for input/output operations like std::cout

// It's generally good practice to include specific headers rather than
// <bits/stdc++.h> for better compilation times and clarity,
// but for competitive programming or quick examples, it's often used.
// For a standard library stack, you'd use #include <stack>

// Using namespace std; // Can be used in .cpp files, but often avoided in headers
// to prevent name collisions. For this example, it's fine.
using namespace std;

// Define a Stack class
class Stack {
private:
    int size; // Maximum capacity of the stack
    int top;  // Index of the top element. -1 means empty.
    int *arr; // Pointer to the dynamically allocated array that stores stack elements

public:
    // Constructor: Initializes the stack with a given capacity
    Stack(int capacity) {
        this->size = capacity;          // Set the maximum size
        this->arr = new int[capacity];  // Dynamically allocate memory for the array
        this->top = -1;                 // Initialize top to -1, indicating an empty stack
        cout << "Stack created with capacity: " << capacity << endl;
    }

    // Destructor: Frees the dynamically allocated memory when the Stack object is destroyed
    ~Stack() {
        delete[] arr; // Deallocate the array memory
        arr = nullptr; // Set pointer to nullptr to avoid dangling pointer issues
        cout << "Stack destroyed." << endl;
    }

    // Push operation: Adds an element to the top of the stack
    void push(int element) {
        if (top >= size - 1) { // Check for Stack Overflow (stack is full)
            cout << "Stack Overflow! Cannot push " << element << endl;
            return; // Exit if stack is full
        }
        top++;          // Increment top to point to the next available position
        arr[top] = element; // Place the element at the new top position
        cout << "Pushed: " << element << endl;
    }

    // Pop operation: Removes and returns the top element from the stack
    int pop() {
        if (top == -1) { // Check for Stack Underflow (stack is empty)
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return a sentinel value or throw an exception to indicate error
        }
        int poppedElement = arr[top]; // Get the element at the current top
        top--;                        // Decrement top to remove the element
        cout << "Popped: " << poppedElement << endl;
        return poppedElement;         // Return the popped element
    }

    // Peek operation: Returns the top element without removing it
    int peek() {
        if (top == -1) { // Check if the stack is empty
            cout << "Stack is Empty! No element to peek." << endl;
            return -1; // Return a sentinel value or throw an exception
        }
        return arr[top]; // Return the element at the current top
    }

    // isEmpty operation: Checks if the stack is empty
    bool isEmpty() {
        return top == -1; // If top is -1, the stack is empty
    }

    // isFull operation: Checks if the stack is full
    bool isFull() {
        return top == size - 1; // If top is at the last index, the stack is full
    }
};

int main() {
    // Create a Stack object dynamically using 'new'
    // 'new Stack(40)' returns a pointer to the newly created Stack object.
    Stack* myStack = new Stack(5); // Creating a stack with a capacity of 5

    // Perform stack operations using the pointer
    myStack->push(10);
    myStack->push(20);
    myStack->push(30);

    cout << "Current top element: " << myStack->peek() << endl; // Should be 30

    myStack->pop(); // Pop 30
    cout << "Current top element after pop: " << myStack->peek() << endl; // Should be 20

    myStack->pop(); // Pop 20
    myStack->pop(); // Pop 10

    cout << "Is stack empty? " << (myStack->isEmpty() ? "Yes" : "No") << endl; // Should be Yes

    myStack->pop(); // Attempt to pop from an empty stack (Underflow)

    myStack->push(100);
    myStack->push(200);
    myStack->push(300);
    myStack->push(400);
    myStack->push(500);

    myStack->push(600); // Attempt to push to a full stack (Overflow)

    cout << "Current top element: " << myStack->peek() << endl; // Should be 500

    // Important: Deallocate the dynamically created object when it's no longer needed
    delete myStack;
    myStack = nullptr; // Set the pointer to nullptr after deletion to prevent dangling pointers

    return 0;
}
