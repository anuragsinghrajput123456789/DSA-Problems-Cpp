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

void printLL(node* &head){
  node* temp = head; 
  while(temp!= nullptr){
    cout << temp->data << endl;
    temp = temp->next; 
  }
}

int lengthLL(node* &head){
  if(head == 0)return 0; 
  return lengthLL(head->next) + 1;
}

bool checkPallindrome(node* &head){
  int n = lengthLL(head);
  int arr[n];
  
  node* temp = head;
  int i=0; 
  while(temp != nullptr && i < n){
    arr[i] = temp->data; 
    temp = temp->next; 
    i++;
  }
  
  
  int s = 0;
  int e = n-1; 
  
  while(s < e){
    if(arr[s] == arr[e]){
      return true; 
    }
    s++;
    e--;
  }
  return false; 
}

int main(){
  node* p1 = new node(1);
  node* p2 = new node(2);
  node* p3 = new node(2);
  node* p4 = new node(1);
  
  p1->next = p2; 
  p2->next = p3;
  p3->next = p4; 
  p4->next = nullptr; 
  
  // printLL(p1);
  
  cout << checkPallindrome(p1);
   
  
  return 0; 
}