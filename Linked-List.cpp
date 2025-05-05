#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};


void linkedList(struct Node* ptr){
  while(ptr != NULL){
   cout << ptr->data << endl; 
   ptr = ptr->next;
  }
}

int main() {
    struct Node* head;
    struct Node* two;
    struct Node* three;

    head = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));

    head->data = 32;
    head->next = two;
    two->data = 23;
    two->next = three;
    three->data = 44;
    three->next = NULL;

    struct Node* ptr = head; // Initialize a pointer to traverse
    linkedList(ptr);
    
    
    return 0;
}