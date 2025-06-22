
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


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
     
     //current seprate linked list of all three;

    while(curr != NULL){
      int value= curr->data; 
      if(value == 0){
         insertAtTail(zeroTail,curr); 
      }
      else if(value == 1){
        insertAtTail(oneTail,curr);
      }
      else if(value == 2){
          insertAtTail(twoTail,curr);
      }
      curr = curr->next; 
    }


    //Now merge all the 3 linked list here...
    if(oneHead ->next != NULL){
        zeroTail ->next = oneHead->next; 
    }
    else{
        //1s list ->empty
       zeroTail->next = twoHead ->next; 
    }

    oneTail -> next = twoHead->next; 
    twoTail -> next = NULL; 


    //setup head; 
    head = zeroHead -> next; 
   
   //delete dummy nodes
   delete zeroHead;
   delete oneHead;
   delete twoHead;


return head; 

}

int main(){


    return 0; 
}