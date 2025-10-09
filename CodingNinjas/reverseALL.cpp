#include <bits/stdc++.h>
using namespace std; 

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    LinkedListNode<int>* prev = NULL; 
    LinkedListNode<int>* curr = head; 
    LinkedListNode<int>* forward = NULL;

     while(curr != NULL){
         forward = curr->next; 
         curr->next = prev; 
         prev = curr; 
         curr = forward;
     }
   
   
       return prev;
}

int main(){


    return 0; 
}