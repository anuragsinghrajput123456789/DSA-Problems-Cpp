#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Print linked list
void printLL(node* head) {
    node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Insert at head
void insertAtHead(node* &head, int data) {
    node* ptr = new node(data);
    ptr->next = head;
    head = ptr;
}

// Insert at tail
void insertAtTail(node* &head, int data) {
    node* ptr = new node(data);
    if (head == nullptr) {
        head = ptr;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = ptr;
}

// Insert at middle (0-based position)
void insertAtMiddle(node* &head, int data, int position) {
    if (position == 0) {
        insertAtHead(head, data);
        return;
    }
    node* temp = new node(data);
    node* ptr = head;
    for (int i = 0; i < position - 1 && ptr != nullptr; i++) {
        ptr = ptr->next;
    }
    if (ptr == nullptr) {
        cout << "Position out of bounds!" << endl;
        delete temp;
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

// Find middle node
node* findMid(node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    node* slow = head;
    node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);

    // Linking nodes
    p1->next = p2;
    p2->next = p3;

    cout << "Original list: ";
    printLL(p1);

    insertAtHead(p1, 255);
    cout << "After inserting 255 at head: ";
    printLL(p1);

    insertAtTail(p1, 59);
    cout << "After inserting 59 at tail: ";
    printLL(p1);

    insertAtMiddle(p1, 100, 2); // insert 100 at position 2
    cout << "After inserting 100 at position 2: ";
    printLL(p1);

    node* mid = findMid(p1);
    if (mid) cout << "Middle element: " << mid->data << endl;

    return 0;
}
