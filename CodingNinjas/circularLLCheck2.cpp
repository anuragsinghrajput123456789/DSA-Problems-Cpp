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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse linked list in groups of k
node* KgroupNodes(node* head, int k) {
    if (head == NULL) return NULL;

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;
    int cnt = 0;

    // Reverse k nodes
    while (curr != NULL && cnt < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    // Recursive call for next group
    if (forward != NULL)
        head->next = KgroupNodes(forward, k);

    // 'prev' is the new head of this reversed group
    return prev;
}

int main() {
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(44);
    node* p5 = new node(55);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    cout << "Original Linked List: ";
    printLL(p1);

    int k = 2;
    node* newHead = KgroupNodes(p1, k);

    cout << "Reversed in groups of " << k << ": ";
    printLL(newHead);

    return 0;
}
