//FLOY LOOP DETECTION ALOG TO FIND LOOP IN A LINKED LIST

#include<bits/stdc++.h>
using namespace std;
bool floyDetectLoop(Node* &head){
  if(head == NULL){
    return false; 
  }
  
  Node* slow = head; 
  Node* fast = head; 
  while(slow != NULL && fast != NULL){
    
    
    slow = slow->next; 
    fast  = fast->next->next; 
    if(slow == fast){
      return true; 
    }
  }
  return false; 
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
  
  cout << detectLoop(one); 
    
  
  
  
  
  return 0; 
}
