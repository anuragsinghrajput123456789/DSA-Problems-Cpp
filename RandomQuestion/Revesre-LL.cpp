//Reverse a Linked-List
#include<bits/stdc++.h>
using namespace std;

struct node
{
    /* data */
    int data; 
    struct node* next; 
};


struct node* ReverseLL(struct node* head,int k){
   //base case
   if(head == NULL){
    //    return ; 
   }

   //Step1: reverse first k nodes baki recursion sabhal lega na bhai
   node* next = NULL; 
   node* curr = head; 
   node* prev = NULL; 
   int cnt = 0;

//K element ko reverse kar doo baki recrusion sambhal lenga bhaiii
   while(curr != NULL & cnt < k){
      next = curr->next; 
      curr->next = prev; 
      prev = curr; 
      curr = next; 
      cnt++;
   }


   //Recursion dekh lega bhai...
   if(next != NULL){
       head->next = ReverseLL(next,k);
   }

   return prev; 
}

struct node* createNode(int data){
   struct node* ptr = (struct node*) malloc (sizeof(struct node));
   ptr->next = nullptr; 
   ptr->data  = data; 
   return ptr; 
}

void insertAtHead(struct node* head,int data){
    struct node* ptr = createNode(data);
    head = head->next;
    ptr->next = head; 
}

void printLL(struct node* head){
  struct node* ptr = head; 
  while(ptr !=NULL){
     cout << " - " << ptr->data << endl; 
     ptr = ptr->next; 
  }
//   cout << endl; 
}




int main(){

    struct node* head = createNode(11);
    struct node* p1 = createNode(22);
    struct node* p2 = createNode(33);
    struct node* p3 = createNode(44);
    struct node* p4 = createNode(55);
    struct node* p5 = createNode(66);

 head->next = p1; 
 p1->next = p2; 
 p2->next = p3; 
 p3->next= p4; 
 p4->next = p5; 


printLL(head);


    return 0; 
}