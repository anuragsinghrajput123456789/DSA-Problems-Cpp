//DELETEION OF A NODE 

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printLinkedList(const Node* head) {
    const Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void deleteNode(int position, Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = nullptr;
        int count = 1;
        while (curr != nullptr && count < position) { // Changed condition
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr == nullptr) { //check if position is valid
            cout << "Position is invalid" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
}

int main() {
    // Create the linked list: 11 -> 2 -> 3 -> 4 -> 5
    
    Node* first = new Node(11);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    // Print the linked list
    cout << "Linked List: ";
    printLinkedList(first);

    // Delete a node
    deleteNode(3, first);
    cout << "Linked List after deleting node at position 3: ";
    printLinkedList(first);

    // Example of deleting the first node
    deleteNode(1, first);
    cout << "Linked List after deleting the first node: ";
    printLinkedList(first);

     // Example of deleting the last node
    deleteNode(3, first);
    cout << "Linked List after deleting the last node: ";
    printLinkedList(first);

    // Clean up the remaining nodes to prevent memory leaks
    Node* current = first;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    first = nullptr;

    return 0;
}