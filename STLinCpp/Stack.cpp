#include <iostream>
#include <stack>     // Required for using std::stack
#include <string>    // Required for using std::string as element type

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions (push) ---" << endl;
    stack<string> myStack;

    // Add elements using push()
    myStack.push("anurag");
    myStack.push("singh");
    myStack.push("rajput"); // This is the top element now

    cout << "Elements added: anurag, singh, rajput" << endl;
    cout << "Current top element (top()): " << myStack.top() << endl; // Expected: rajput


    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myStack: " << myStack.size() << endl; // Expected: 3

    if (myStack.empty()) {
        cout << "myStack is empty." << endl;
    } else {
        cout << "myStack is NOT empty." << endl;
    }


    cout << "\n--- 3. Modifiers (pop) ---" << endl;

    cout << "Popping top element (pop()): " << myStack.top() << endl;
    myStack.pop(); // Removes "rajput"

    cout << "New top element after pop(): " << myStack.top() << endl; // Expected: singh
    cout << "Size after pop(): " << myStack.size() << endl; // Expected: 2

    cout << "Popping top element (pop()): " << myStack.top() << endl;
    myStack.pop(); // Removes "singh"

    cout << "New top element after pop(): " << myStack.top() << endl; // Expected: anurag
    cout << "Size after pop(): " << myStack.size() << endl; // Expected: 1


    cout << "\n--- 4. Iterating and Popping All Elements ---" << endl;
    // To see all elements, you must pop them one by one.
    // Stacks don't provide iterators for direct traversal (like for-each loop).
    cout << "Popping all remaining elements:" << endl;
    while (!myStack.empty()) {
        cout << "  Popping: " << myStack.top() << endl;
        myStack.pop();
    }
    cout << "Size after popping all elements: " << myStack.size() << endl; // Expected: 0
    if (myStack.empty()) {
        cout << "myStack is now empty." << endl;
    }


    cout << "\n--- 5. Swap Function ---" << endl;
    stack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    stack<int> stack2;
    stack2.push(30);
    stack2.push(40);
    stack2.push(50);

    cout << "Before swap:" << endl;
    cout << "  Stack1 top: " << stack1.top() << ", size: " << stack1.size() << endl;
    cout << "  Stack2 top: " << stack2.top() << ", size: " << stack2.size() << endl;

    stack1.swap(stack2);

    cout << "After swap:" << endl;
    cout << "  Stack1 top: " << stack1.top() << ", size: " << stack1.size() << endl; // Stack1 now has elements of original Stack2
    cout << "  Stack2 top: " << stack2.top() << ", size: " << stack2.size() << endl; // Stack2 now has elements of original Stack1

    return 0;
}
