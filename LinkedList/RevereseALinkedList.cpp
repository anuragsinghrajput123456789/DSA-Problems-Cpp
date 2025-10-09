#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// ✅ Iterative approach
void reverseLL(node* &head) {
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// ✅ Recursive approach (tail recursion style)
void reverseRec(node* &head, node* curr, node* prev) {
    // base case
    if (curr == NULL) {
        head = prev;
        return;
    }

    node* forward = curr->next;  // store next before recursion
    reverseRec(head, forward, curr);
    curr->next = prev;  // reverse link while returning
}

// ✅ Recursive approach (easier version returning new head)
node* reverseRec2(node* head) {
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the smaller list
    node* newHead = reverseRec2(head->next);

    // fix current node
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main() {
    // create linked list
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(44);
    node* p5 = new node(55);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    cout << "Original Linked List:" << endl;
    printLL(p1);

    // ✅ Iterative reversal
    reverseLL(p1);
    cout << "\nAfter Iterative Reverse:" << endl;
    printLL(p1);

    // ✅ Recursive reversal (method 1)
    reverseRec(p1, p1, NULL);
    cout << "\nAfter Recursive Reverse (Method 1):" << endl;
    printLL(p1);

    // ✅ Recursive reversal (method 2 - simpler)
    p1 = reverseRec2(p1);
    cout << "\nAfter Recursive Reverse (Method 2):" << endl;
    printLL(p1);

    return 0;
}
