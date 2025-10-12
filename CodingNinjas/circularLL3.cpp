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

// Normal print (for non-circular lists)
void printLL(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print circular linked list safely
void printCircularLL(node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head && temp != NULL);

    cout << "(back to head → " << head->data << ")\n";
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

    // Recursive call for remaining list
    if (forward != NULL)
        head->next = KgroupNodes(forward, k);

    return prev; // new head of this reversed group
}

// Check if the linked list is circular
bool isCircularList(node* head) {
    if (head == NULL)
        return false;

    node* temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
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
    p5->next = p1; // ✅ make it circular

    cout << "Checking if list is circular: " 
         << (isCircularList(p1) ? "Yes" : "No") << endl;

    if (isCircularList(p1))
        printCircularLL(p1);
    else
        printLL(p1);

    return 0;
}
