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

void linkedList(Node* &head){
  Node* temp = head; 
  while(temp != NULL){
    cout << temp->data << endl; 
    temp = temp->next; 
  }
}

bool pallindrome(Node* &head){

  //dynamically array implementation
  vector<int> arr;
  Node* temp = head;
  while(temp != NULL){
   arr.push_back(temp->data);
   temp = temp->next;
  }
  int s= 0;
  int e = arr.size() - 1;
 while(s <= e){
  if(arr[s] != arr[e]){
   return false;
  }
  s++;
  e--;
 }
 return true;
}


int main(){
  
  
  Node* one = new Node(11);
  Node* two = new Node(22);
  Node* three = new Node(33);
  Node* four = new Node(44);
  
  one->next = two; 
  two->next = three; 
  three->next =four; 
  four->next= NULL; 
  
  
   cout << pallindrome(one) << endl; 
  
  
  
  
  
  return 0; 
}
