// MERGE SORT A LINED LIST BABY



#include <iostream>
using namespace std;

class Node { // Changed struct to class
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* findMid(Node* head) {
    if (head == NULL) { // Added null check
        return NULL;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) { // Corrected parameter order
    if (left == NULL) {
        return right;
    }

    if (right == NULL) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    // merge 2 sorted Linked List
    while (left != NULL && right != NULL) { // Changed the condition
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

    // agar ek list empty ho gayii hai to
    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    // agar right wali list empty ho gayii hai to
    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    Node* ret = ans->next;
    delete ans;
    return ret;
}

Node* mergeSort(Node* head) {
    // base case yeh raha hai bhai
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = findMid(head);
    if (mid == NULL)
        return head;

    // dividing the ll in two halfes bhai..
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL; // Important:  Break the list

    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both halfes of the linked list bhai...
    Node* result = merge(left, right);
    return result;
}

void printLL(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " "; // Changed output format
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node* one = new Node(3);
    Node* two = new Node(4);
    Node* three = new Node(7);
    Node* four = new Node(0);
    Node* five = new Node(1);
    Node* siz = new Node(35);
    Node* seven = new Node(99);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = siz;
    siz->next = seven;

    cout << "Original List: ";
    printLL(one);

    Node* sortedList = mergeSort(one); // Changed function name to mergeSort
    cout << "Sorted List: ";
    printLL(sortedList);

    return 0;
}
