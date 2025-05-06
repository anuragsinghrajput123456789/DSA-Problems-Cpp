// LINKED LIST OPERATION ARE THERE...

#include<bits/stdc++.h>
using namespace std; 

class Node{
  public: 
  int data; 
  Node* next;
  
  // Constructor
  Node(int data){
    this -> data = data; 
    this -> next = NULL; 
  }
};

// Function to insert a node at the head of the linked list
void insertAthead(Node* &head, int data){
  // Create a new node
  Node* temp = new Node(data);
  temp->next = head; 
  head = temp;
}

// Function to print the linked list
void printLinkedList(Node* head){
  Node* ptr = head; 
  while(ptr != NULL){
    cout << ptr->data << " "; 
    ptr = ptr->next; 
  }
  cout << endl; // Print a newline after printing the list
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &tail, int data){
  // Create a new node
  Node* temp = new Node(data);
  tail->next = temp; 
  tail = temp; 
}

// Function to insert a node at a specific position in the linked list
void insertAtMiddle(Node* &head, int position, int data){
  Node* temp = head; 
  int cnt = 1; 
  
  // Find the node just before the desired position
  while(cnt < position - 1 && temp != NULL){
    temp = temp->next; 
    cnt++; 
  }
  
  // If the position is valid
  if (temp != NULL) {
    // Create a new node
    Node* newNode = new Node(data); 
    newNode->next = temp->next; 
    temp->next = newNode; 
  } else {
    cout << "Invalid position" << endl;
  }
}

int main(){
  Node * node1 = new Node(12);
  Node * node2 = new Node(13);
  Node * node3 = new Node(14);
  Node * node4 = new Node(15);
  Node * node5 = new Node(16);
  
  node1->next = node2; 
  node2->next = node3; 
  node3->next = node4; 
  node4->next = node5; 
  
  Node* head = node1; // Initialize head pointer
  Node* tail = node5; // Initialize tail pointer
  
  cout << "Original Linked List: " << endl;
  printLinkedList(head);  
  
  cout << "After inserting 2389 at the head: " << endl;
  insertAthead(head, 2389);
  printLinkedList(head); 
  
  cout << "After inserting 99 at position 3: " << endl;
  insertAtMiddle(head, 3, 99);
  printLinkedList(head); 
 
  return 0; 
}