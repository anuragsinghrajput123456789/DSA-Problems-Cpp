// SIMPLE LOOP DETECTION IN A LINLED USING MAP'S


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

bool detectLoop(Node* &head){
  if(head == NULL){
    return false; 
  }
  
  map<Node*,bool> visited; 
  
  Node* temp = head; 
  while(temp != NULL){
    //cycle is present
    
    if(visited[temp] == true){
      cout << "Present on element : " << temp->data << endl; 
      return 1;   
    } 
    
    visited[temp] = true; 
    
    temp= temp->next; 
  }
  
  return false; 
}

void printLL(Node* &head){
  Node* temp = head; 
  while(temp != NULL){
    cout << "->" << temp->data; 
    temp = temp->next; 
  }
  cout << endl; 
}

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
