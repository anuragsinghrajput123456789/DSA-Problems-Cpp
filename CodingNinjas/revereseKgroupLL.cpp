#include<bits/stdc++.h>
using namespace std;    

class Node{
    int data; 
    Node* next; 

    Node(int data){
       this->data = data; 
       this->next = nullptr;
    }
};

int count(Node* head){

    int cnt = 0;

    while(head != NULL){

        head = head -> next;

        cnt++;

    }

    return cnt;

}

 

Node* kReverse(Node* head, int k) {

    if(head == NULL) return head;

    

    Node* forward = NULL;

    Node* curr = head;

    Node* prev = NULL;

    int cnt = 0;

    while(curr != NULL && cnt < k){

        forward = curr -> next;

        curr -> next = prev;

        prev = curr;

        curr = forward;

        cnt++;

    }

    if(forward != NULL && count(forward)>=k) {

        head->next = kReverse(forward, k);

    }

    else{

        head -> next = forward;

    }

    return prev;

}

int main(){



    return 0; 
}