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

void printLL(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(node* head) {
    if (head == nullptr) return 0;
    return 1 + lengthOfLL(head->next);
}

void sortLL(node* &head) {
    if (head == nullptr || head->next == nullptr) return;

    int n = lengthOfLL(head);

    for (int i = 0; i < n - 1; i++) {
        node* curr = head;
        node* next = head->next;

        for (int j = 0; j < n - i - 1 && next != nullptr; j++) {
            if (curr->data > next->data) {
                swap(curr->data, next->data); // ✅ swap DATA, not pointers
            }
            curr = next;
            next = next->next;
        }
    }
}

void RemoveDuplicate(node* &head) {
    if (head == nullptr) return;

    node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            node* dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        } else {
            temp = temp->next;
        }
    }
}

int main() {
    // Creating unsorted linked list: 44 -> 22 -> 11 -> 33 -> 55 -> 22
    node* p1 = new node(44);
    node* p2 = new node(22);
    node* p3 = new node(11);
    node* p4 = new node(33);
    node* p5 = new node(55);
    node* p6 = new node(22);

    // Linking nodes
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    cout << "Length of Linked List: " << lengthOfLL(p1) << endl;

    cout << "Original Linked List: ";
    printLL(p1);

    sortLL(p1);

    cout << "After Sorting: ";
    printLL(p1);

    RemoveDuplicate(p1);

    cout << "After Removing Duplicates: ";
    printLL(p1);

    return 0;
}
