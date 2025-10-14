#include<bits/stdc++.h>
using namespace std; 

class Node{
  int data; 
  Node* next; 
  
  Node(int data){
    this->data = data; 
    this->next = NULL;
  }
};

Node* sortListdataReplacement(Node *head){
    // Write your code here.
    Node* temp = head; 
    int zeroCount = 0;
    int oneCount = 1; 
    int twoCount = 2; 

    while(temp != nullptr){
        if(temp->data == 0){
           zeroCount++; 
        }
        else if(temp->data == 1){
          oneCount++; 
        }
        else{
            twoCount++;
        }
        temp = temp->next; 
    }

    temp = head; 
    
    while(temp != nullptr){
      if(zeroCount != 0){
         temp->data = 0; 
         zeroCount--;
      }
      else if(oneCount != 1){
        temp->data = 1; 
        oneCount--;
      }
      else{
          temp->data = 2;
          twoCount--;
      }
      temp = temp->next; 
    }

return head;
}

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr; 
    tail = curr; 
}

Node* sortList(Node *head){
    // Write your code here.
   
   Node* zeroHead = new Node(-1);
   Node* zeroTail = zeroHead;
   Node* oneHead = new Node(-1);
   Node* oneTail = oneHead;
   Node* twoHead = new Node(-1);
   Node* twoTail = twoHead;

   Node* curr = head;

   while(curr != nullptr){
       int value = curr->data; 
       if(value == 0){
          insertAtTail(zeroTail,curr);
       }
       else if(value == 1){
          insertAtTail(oneTail,curr);
       }
       else{
           insertAtTail(twoTail,curr);
       }
       curr = curr->next; 
   }

    //merge 3 sublist teeno list ko merge kardo bhai
    // 1s list not empty
    if(oneHead -> next != nullptr){
        zeroTail->next = oneHead->next; 
    }
    else{
         zeroTail->next = twoHead->next; 
    }

    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

// setup head
    head = zeroHead->next;
//delete dummy nodes here...
   delete zeroHead;
   delete oneHead;
   delete twoHead;

   return head;
}

void printLL(Node* &head){
  node* temp = head; 
  
  while(temp != NULL){
    cout << temp->data << endl; 
    temp = temp->next; 
  }
  cout << endl; 
}

int main(){
  
  
  
  return 0; 
}
