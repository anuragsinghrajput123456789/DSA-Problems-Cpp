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

// Print non-circular list
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

// Check if linked list is circular using map
bool isCircularList(node* head) {
    if (head == nullptr)
        return false;

    unordered_map<node*, bool> visited;
    node* temp = head;

    while (temp != nullptr) {
        // if current node already visited → circular
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
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
