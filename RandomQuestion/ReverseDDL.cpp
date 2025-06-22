#include<bits/stdc++.h>
using namespace std; 

//Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{   
    // Write your code here 
    if(head == NULL || head->next == NULL){
        return head; 
    }  
    
    Node* tail = NULL; 
    Node* curr = head; 

    while(curr != NULL){
       tail = curr->prev; 
       curr->prev = curr->next; 
       curr->next = tail; 
       curr = curr->prev; 
    }

    return tail->prev; 

}

int main(){


    return 0; 
}