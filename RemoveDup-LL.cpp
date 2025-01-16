
#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == nullptr) { // Check for malloc failure
        cerr << "Memory allocation failed!" << endl;
        exit(1);
    }
    ptr->next = NULL;
    ptr->data = data;
    return ptr;
}

struct node* insertAtHead(struct node* head, int data) {
    struct node* ptr = createNode(data);
    ptr->next = head; // Correct insertion at head
    return ptr;      // Return the new head
}

void printLL(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        cout << " " << ptr->data;
        ptr = ptr->next;
    }
    cout << endl; // Add a newline for better output
}

struct node* removeDup(struct node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Nothing to remove if list is empty or has only one node
    }

    struct node* curr = head;
    while (curr != nullptr && curr->next != nullptr) { // Check curr->next to avoid segfault
        if (curr->data == curr->next->data) {
            struct node* del = curr->next;
            curr->next = curr->next->next;
            free(del);
        } else {
            curr = curr->next; // Move to the next node only if no deletion happened
        }
    }
    return head; // Return the modified head
}

int main() {
    struct node* head = createNode(11);
    struct node* p1 = createNode(22);
    struct node* p2 = createNode(22);
    struct node* p3 = createNode(22);
    struct node* p4 = createNode(55);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;

    printLL(head);

    head = removeDup(head); // Assign the returned head
    printLL(head);

    // Free allocated memory (important to prevent memory leaks)
    struct node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}