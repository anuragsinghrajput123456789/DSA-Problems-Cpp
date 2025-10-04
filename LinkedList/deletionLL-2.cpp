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
    
    //destructor
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

// ✅ FIXED deletion by position
void deletionNode(node* &head,int position){
    if(head == nullptr) return; 

    if(position == 1){ // delete head node
        node* temp = head;
        head = head->next; 
        temp->next = nullptr;
        delete temp;
        return;
    }

    node* curr = head;
    node* prev = nullptr;
    int cnt = 1; 

    while(curr != nullptr && cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if(curr == nullptr) return; // position > length

    prev->next = curr->next;
    curr->next = nullptr;
    delete curr; 
}

// ✅ FIXED deletion by data
void deletionNodeData(node* &head,int data){
    if(head == nullptr) return; 

    // case: head contains data
    if(head->data == data){
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    node* curr = head;
    node* prev = nullptr;

    while(curr != nullptr && curr->data != data){
        prev = curr;
        curr = curr->next;
    }

    if(curr == nullptr) return; // data not found

    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}


int main(){
    node* head = new node(11);

    insertAtHead(head,22);
    insertAtHead(head,33);
    insertAtHead(head,44);
    
    insertAtTail(head,55);
    insertAtTail(head,44);

    cout << "Original list: ";
    printLL(head);

    // delete 2nd node
    deletionNode(head,2);
    cout << "After deleting position 2: ";
    printLL(head);

    // delete by value
    deletionNodeData(head,44);
    cout << "After deleting node with data 44: ";
    printLL(head);

    return 0; 
}
