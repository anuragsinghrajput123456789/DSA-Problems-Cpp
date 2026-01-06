#include<bits/stdc++.h>
using namespace std; 

class Node{
    public: 
    int data; 
    Node* next; 

    Node(int data){
        this->data = data; 
        this->next = nullptr; 
    }
};





Node* mergeKLists(vector<Node*> &lists){

    // Write your code here.

    int K=lists.size();

        Node *head=new Node(-1), *temp=head;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<K;i++){
            Node *temp1=lists[i];
            while(temp1!=NULL){
                pq.push(temp1->data);
                temp1=temp1->next;
            }
        }

        while(!pq.empty()){
            Node *newNode = new Node(pq.top());
            pq.pop();
            head->next=newNode;
            head=head->next;
        }
    return temp->next;  
}

int main(){




    return 0;
}