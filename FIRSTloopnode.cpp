//FINDING THE FIRST LOOP NODE IN A LINKED LIST BHAI.... 

#include<bits/stdc++.h>
using namespace std; 


class Node{
 public: 
  int data; 
  Node* next; 
  
  Node(int data){
    this -> data = data; 
    this-> next = NULL; 
  }
};

Node* floyDetectLoop(Node* &head){
  if(head == NULL){
    return NULL; 
  }
  
  Node* slow = head; 
  Node* fast = head; 
  
  while(slow != NULL && fast != NULL){
    fast = fast->next; 
    if(fast != NULL){
      fast = fast->next; 
    }
    slow = slow->next; 
    if(slow == fast){
      // cout << "present at" << slow->data << endl; 
      return slow; 
    }
  }
}



void printLL(Node* &head){
  Node* temp = head; 
  while(temp != NULL){
    cout << "->" << temp->data; 
    temp = temp->next; 
  }
  cout << endl; 
}

Node* getStartingNode(Node* head){
  if(head == NULL){
    return NULL; 
  }
  
  Node* intersection = floyDetectLoop(head);
  Node* slow = head; 
  while(slow != intersection){
     slow = slow->next; 
     intersection = intersection->next; 
  }
 return slow; 
}

int main(){
  
  Node* one = new Node(1); 
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);
  Node* five = new Node(5);
  
  one->next = two; 
  two->next = three; 
  three->next = four; 
  four->next = five; 
  five->next = NULL; 
  
  Node* tail = five; 
  tail->next = three;
  
 Node* loop = getStartingNode(one); 
 cout << loop->data << endl; 
 
 
  
  
  
  
  return 0; 
}
