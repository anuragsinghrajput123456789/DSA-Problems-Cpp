#include <iostream>
#include <queue>     // Required for using std::queue
#include <string>    // Required for using std::string as element type

using namespace std; // Using the standard namespace to avoid std:: prefix

int main() {
    cout << "--- 1. Initialization and Basic Additions (push) ---" << endl;
    queue<string> myQueue;

    // Add elements using push()
    myQueue.push("anurag"); // First in
    myQueue.push("singh");
    myQueue.push("rajput"); // Last in

    cout << "Elements added: anurag, singh, rajput (in order)" << endl;
    cout << "Current front element (front()): " << myQueue.front() << endl; // Expected: anurag
    cout << "Current back element (back()): " << myQueue.back() << endl;   // Expected: rajput


    cout << "\n--- 2. Capacity Functions ---" << endl;
    cout << "Current size of myQueue: " << myQueue.size() << endl; // Expected: 3

    if (myQueue.empty()) {
        cout << "myQueue is empty." << endl;
    } else {
        cout << "myQueue is NOT empty." << endl;
    }


    cout << "\n--- 3. Modifiers (pop) ---" << endl;

    cout << "Popping front element (pop()): " << myQueue.front() << endl;
    myQueue.pop(); // Removes "anurag"

    cout << "New front element after pop(): " << myQueue.front() << endl; // Expected: singh
    cout << "Size after pop(): " << myQueue.size() << endl; // Expected: 2

    cout << "Popping front element (pop()): " << myQueue.front() << endl;
    myQueue.pop(); // Removes "singh"

    cout << "New front element after pop(): " << myQueue.front() << endl; // Expected: rajput
    cout << "Size after pop(): " << myQueue.size() << endl; // Expected: 1


    cout << "\n--- 4. Iterating and Popping All Elements ---" << endl;
    // To see all elements, you must pop them one by one.
    // Queues, like stacks, don't provide iterators for direct traversal (like for-each loop).
    cout << "Popping all remaining elements:" << endl;
    while (!myQueue.empty()) {
        cout << "  Popping: " << myQueue.front() << endl;
        myQueue.pop();
    }
    cout << "Size after popping all elements: " << myQueue.size() << endl; // Expected: 0
    if (myQueue.empty()) {
        cout << "myQueue is now empty." << endl;
    }


    cout << "\n--- 5. Swap Function ---" << endl;
    queue<int> queue1;
    queue1.push(10);
    queue1.push(20);

    queue<int> queue2;
    queue2.push(30);
    queue2.push(40);
    queue2.push(50);

    cout << "Before swap:" << endl;
    cout << "  Queue1 front: " << queue1.front() << ", back: " << queue1.back() << ", size: " << queue1.size() << endl;
    cout << "  Queue2 front: " << queue2.front() << ", back: " << queue2.back() << ", size: " << queue2.size() << endl;

    queue1.swap(queue2);

    cout << "After swap:" << endl;
    cout << "  Queue1 front: " << queue1.front() << ", back: " << queue1.back() << ", size: " << queue1.size() << endl; // Queue1 now has elements of original Queue2
    cout << "  Queue2 front: " << queue2.front() << ", back: " << queue2.back() << ", size: " << queue2.size() << endl; // Queue2 now has elements of original Queue1

    return 0;
}
