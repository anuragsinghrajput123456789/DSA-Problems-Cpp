#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) : data(data), next(nullptr) {}
};

// Utility to find the middle of the list
node* findMiddle(node* head) {
    node* slow = head;
    node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Reverse a linked list
node* reverseLL(node* head) {
    node* prev = nullptr;
    node* curr = head;
    while (curr != nullptr) {
        node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Check if linked list is palindrome
bool checkPalindrome(node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // Step 1: Find middle
    node* mid = findMiddle(head);

    // Step 2: Reverse second half
    node* secondHalf = reverseLL(mid);

    // Step 3: Compare first half and reversed second half
    node* firstHalf = head;
    node* tempSecond = secondHalf;
    bool isPalin = true;
    while (tempSecond != nullptr) {
        if (firstHalf->data != tempSecond->data) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // Step 4: Optional: Restore the list
    reverseLL(secondHalf);

    return isPalin;
}

int main() {
    node* p1 = new node(11);
    node* p2 = new node(2);
    node* p3 = new node(3);
    node* p4 = new node(2);
    node* p5 = new node(11);

    // Creating linked list: 11->2->3->2->11
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    if (checkPalindrome(p1))
        cout << "List is palindrome" << endl;
    else
        cout << "List is not palindrome" << endl;

    return 0;
}
