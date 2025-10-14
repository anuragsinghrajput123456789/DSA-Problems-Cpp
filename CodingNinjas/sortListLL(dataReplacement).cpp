#include<bits/stdc++.h>
using namespace std; 

class node{
  int data; 
  node* next; 
  
  node(int data){
    this->data = data; 
    this->next = NULL;
  }
};

node* sortList(Node *head){
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

void printLL(node* &head){
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
