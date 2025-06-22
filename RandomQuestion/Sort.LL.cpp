#include<bits/stdc++>
using namespace  std; 
 // namespace  std; 




/*
Following is the class structure of the Node class:

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
*/

Node* sortList(Node *head){
    // Write your code here.
   int zeroCount = 0; 
   int oneCount = 0; 
   int twoCout = 0; 

   Node* temp = head; 
   while(temp != NULL){
       if(temp -> data == 0){
         zeroCount++; 
       }
      else if(temp->data == 1){
           oneCount++; 
       }
       else if(temp->data== 2){
          twoCout++; 
       }
       temp= temp->next;
   }
    
    temp = head; 

    while(temp != NULL){
       if(zeroCount != 0){
          temp ->data = 0;
          zeroCount--; 
       }
       else if(oneCount != 0){
            temp ->data = 1; 
            oneCount--; 
       }
    else if(twoCout != 0){
        temp->data = 2; 
         twoCout--; 
    }
    temp = temp->next; 
  }
  return head; 
}


int main(){



    return 0; 
}