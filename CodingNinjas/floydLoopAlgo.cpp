#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Detect loop using Floyd's algorithm and return start node of loop if exists
Node* detectAndGetLoopStart(Node* head) {
    if (!head) return nullptr;
    Node* slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // loop detected
    }
    if (!fast || !fast->next) return nullptr; // no loop

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // start of loop
}

// Remove loop if present
void removeLoop(Node* head) {
    Node* start = detectAndGetLoopStart(head);
    if (!start) return;
    Node* temp = start;
    while (temp->next != start) temp = temp->next;
    temp->next = nullptr;
}

// Print list safely
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    head->next->next->next->next = new Node(55);

    head->next->next->next->next->next = head->next; // loop 55->33

    Node* loopStart = detectAndGetLoopStart(head);
    cout << "Loop starts at: " << (loopStart ? loopStart->data : -1) << endl;

    removeLoop(head);

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}