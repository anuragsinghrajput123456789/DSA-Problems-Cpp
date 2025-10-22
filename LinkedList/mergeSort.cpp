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

// Function to find middle node of linked list
node* middleofLL(node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    node* slow = head;
    node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted linked lists
node* merge(node* left, node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    node* ans = new node(-1); // dummy node
    node* temp = ans;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // attach remaining nodes
    while (left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    node* result = ans->next;
    delete ans; // free dummy node
    return result;
}

// Merge Sort on linked list
node* mergeSort(node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // split into two halves
    node* mid = middleofLL(head);
    node* left = head;
    node* right = mid->next;
    mid->next = nullptr;

    // recursive sort
    left = mergeSort(left);
    right = mergeSort(right);

    // merge sorted halves
    return merge(left, right);
}

// Print Linked List
void printLL(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* p1 = new node(15);
    node* p2 = new node(52);
    node* p3 = new node(35);
    node* p4 = new node(440);
    node* p5 = new node(558);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    cout << "Original Linked List: ";
    printLL(p1);

    node* sortedHead = mergeSort(p1);

    cout << "Sorted Linked List: ";
    printLL(sortedHead);

    return 0;
}
