#include<bits/stdc++.h>
using namespace std; 

class node {
public: 
    int data; 
    node* next; 
  
    node(int data){
        this->data = data; 
        this->next = nullptr;
    }
    
    ~node(){
      int value = this->data; 
      if(this->next != nullptr){
        delete next;
        this->next = nullptr;
      }
      cout << "memory is free for node with data " << value << endl;
    }
};

void printLL(node* head){
    node *ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next; 
    }
    cout << endl;
}

void insertAtHead(node* &head, int data){
    node* ptr = new node(data);
    ptr->next = head; 
    head = ptr; 
}

void insertAtTail(node* &head, int data){
    if(head == nullptr){   // handle empty list
        head = new node(data);
        return;
    }
    node* temp = head; 
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new node(data);
}

void insertAtPosition(node* &head, int data, int position){
    if(position == 0){   // inserting at head
        insertAtHead(head, data);
        return;
    }
    
    node* temp = head;
    for(int i = 1; i < position && temp != nullptr; i++){
        temp = temp->next; 
    }
    
    if(temp == nullptr){   // if position > length, insert at tail
        insertAtTail(head, data);
        return;
    }
    
    node* ptr = new node(data);
    ptr->next = temp->next;
    temp->next = ptr; 
}

void deletionLL(node* &head,int position){
 
 //deleting first or start node
 if(position == 1){
   //memeory fress start node
   node* temp = head; 
   head = head->next; 
   temp->next = nullptr;
   delete temp;
 }
 else{
   //deleting any middle or last node
   node* curr = head;
   node* prev = nullptr;
   int cnt = 1;
   while(cnt < position){
      prev = curr;
      curr = curr->next; 
      cnt++;
    }
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
 }
}


int main(){
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(44);
    node* p5 = new node(55);
  
    // linking this...
    p1->next = p2; 
    p2->next = p3; 
    p3->next = p4; 
    p4->next = p5; 
  
    cout << "Original list: ";
    printLL(p1);

    // insertAtPosition(p1, 99, 1);   // insert at head
   // insert beyond length -> goes to tail

    // cout << "After insertions: ";
    // printLL(p1);
    deletionLL(p1,3);
    printLL(p1);
  
    return 0; 
}
