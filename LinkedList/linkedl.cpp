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

void printLL(node* p1){
  node* temp = p1; 
  
  while(temp != nullptr){
    cout << temp->data << endl; 
    temp = temp->next;
  }
}

void insertAthead(node* &head,int data){
  //new node creation here...
  node* temp = new node(data);
  temp->next = head;
  // head = head->next; 
  head = temp;
}

void insertAtTail(node* &head,int data){
  //creating a new node
  node* temp = new node(data);
  node* ptr = head; 
  while(ptr->next != nullptr){
    ptr = ptr->next; 
  }
  
  //now ptr->next == nullptr
  ptr->next = temp;
  temp->next = nullptr;
}

int main(){
   node *p1 = new node(11);
   node *p2 = new node(22);
   node *p3 = new node(33);
   node *p4 = new node(44);
   node *p5 = new node(55);
   node *p6 = new node(66); 
   
   
  //linking the nodes here...
   p1->next = p2; 
   p2->next= p3; 
   p3->next = p4; 
   p4->next = p5; 
   p5->next = p6; 
   p6->next = nullptr;
   
   
  // printLL(p1);
   insertAthead(p1,279);
   
   insertAtTail(p1,135);
   printLL(p1);
  
   
  
  
  return 0;
}
