
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

  ~node() {
    cout << "Memory is free for node with data " << data << endl;
  }
};

void insertNode(node* &tail, int element, int data) {
  if (tail == NULL) {
    node* newNode = new node(data);
    tail = newNode;
    newNode->next = newNode;
    return;
  }

  node* curr = tail;
  while (curr->data != element) {
    curr = curr->next;
    if (curr == tail) {
      cout << "Element " << element << " not found\n";
      return;
    }
  }

  node* temp = new node(data);
  temp->next = curr->next;
  curr->next = temp;

  if (curr == tail) tail = temp;
}

void printCLL(node* tail) {
  if (tail == NULL) {
    cout << "List is empty" << endl;
    return ; 
  }

  node* temp = tail->next;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != tail->next);
  cout << endl;
}

void deleteNode(node* &tail,int value){
  //empty list
  if(tail == NULL){
    cout << "List is empty, please check again" << endl; 
    return;
  }
  else{
    //non-empty
    
    //assuming that the value si present in the cll
    node* prev = tail; 
    node* curr = prev->next;
    
    while(curr->data != value){
       prev = curr; 
       curr = curr->next;
    }
    prev->next = curr->next; 
    
    // 1 node linked list 
    if(curr == prev){
      tail = nullptr; 
    }
    
    
    // if the number of nodes is >= 2 baby...
    if(tail == curr){
      tail = prev; 
    }
    
    
    curr->next = NULL;
    delete curr;
  }
}

int main() {
  node* tail = NULL;

  insertNode(tail, 5, 3); // empty list → create node 3
  insertNode(tail, 3, 4); // insert 4 after 3
  insertNode(tail, 4, 6); // insert 6 after 4
  insertNode(tail, 6, 5); // insert 5 after 6
  insertNode(tail,3,99);


  printCLL(tail);
  
  deleteNode(tail,99);
  
  printCLL(tail);
  
  return 0;
}
