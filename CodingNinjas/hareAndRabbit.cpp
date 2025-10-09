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

int getLength(node* head) {
    if (head == NULL) return 0;
    return 1 + getLength(head->next);
}

node* getMiddle(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // special case: only two nodes
    if (head->next->next == NULL) {
        return head->next;
    }

    node* slow = head;
    node* fast = head;

    // Correct loop condition
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    cout << "Linked List: ";
    printLL(p1);

    cout << "Length: " << getLength(p1) << endl;

    node* mid = getMiddle(p1);
    cout << "Middle Node Data: " << mid->data << endl;

    return 0;
}
