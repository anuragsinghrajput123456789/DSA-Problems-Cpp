#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// Insert at head
void insertAtHead(node* &head, int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

// Print linked list
void printLL(node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Iterative reverse
node* reverseLL(node* head){
    node* prev = nullptr;
    node* curr = head;

    while(curr != nullptr){
        node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

// Recursive reverse (method 1)
void reverseRec(node* &head, node* curr, node* prev){
    if(curr == nullptr){
        head = prev;
        return;
    }

    node* forward = curr->next;
    reverseRec(head, forward, curr);
    curr->next = prev;
}

// Recursive reverse (method 2 - best one)
node* reverseRec1(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* newHead = reverseRec1(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main(){
    node* head = nullptr;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original: ";
    printLL(head);

    // Iterative reverse
    head = reverseLL(head);
    cout << "Iterative Reverse: ";
    printLL(head);

    // Recursive reverse (method 1)
    reverseRec(head, head, nullptr);
    cout << "Recursive Reverse (method 1): ";
    printLL(head);

    // Recursive reverse (method 2)
    head = reverseRec1(head);
    cout << "Recursive Reverse (method 2): ";
    printLL(head);

    return 0;
}