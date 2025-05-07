//LINKED LIST ReverseED

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void printLinkedList(const Node* head) {
    const Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLinkedList(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev; // Reverse the pointer
        prev = curr;      // Move prev to current
        curr = next;      // Move current to next
    }
    head = prev; // Update head to the new first node
}

int main() {
    // Create the linked list: 11 -> 22 -> 33 -> 44
    Node* first = new Node(11);
    Node* second = new Node(22);
    Node* third = new Node(33);
    Node* fourth = new Node(44);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(first);

    // Reverse the linked list
    reverseLinkedList(first);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(first);

    // Don't forget to deallocate memory to prevent memory leaks
    Node* current = first;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    first = nullptr; // Set head to nullptr after deleting

    return 0;
}