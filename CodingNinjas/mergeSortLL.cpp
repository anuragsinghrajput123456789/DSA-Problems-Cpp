#include<bits/stdc++.h>
using namespace std; 
    
class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
};

node *findMid(node* head){
    node* slow = head; 
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
       slow = slow->next; 
       fast = fast->next->next; 
    }
    return slow;
}


node* merge(node* left,node* right){
   //if left wala part is empty then right part return 
    if (left == NULL) {
      return right; 
}

  //if right wala part is empty then right part return 
    if(right == NULL){
      return left; 
    }

    node* ans = new node(-1);
    node* temp = ans;

    //merge 2 sorted linkedlist here...
    while (left != NULL && right != NULL) {
        if(left->data < right->data){
            //ans wali linked list me add kar rahe hai
            temp->next = left; 
            temp = left; 
            left = left->next; 
        }
        else{
            temp->next = right; 
            temp = right; 
            right = right->next; 
        }
    }

    while (left != NULL) {
         temp->next = left; 
            temp = left; 
            left = left->next; 
    }

     while (right != NULL) {
         temp->next = right; 
            temp = right; 
            right = right->next; 
    }

    ans = ans->next; 

    return ans; 
}

node* mergeSort(node *head) {
    // Write your code here.
    //base case
    if (head == NULL || head->next == NULL){
        return head; 
    }

    node* mid = findMid(head);

    node* left = head; 
    node* right = mid->next;
    //right part linked list 
    mid->next = NULL;

    //Recursive calls to sort both parts of arrays...
     left = mergeSort(left);
     right = mergeSort(right);

    //Merge both left and right parts of halfes
    node* result = merge(left,right);

    return result; 

}

int main(){



  return 0; 
}
