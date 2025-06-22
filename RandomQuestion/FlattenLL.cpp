#include<bits/stdc++.h>
using namespace std; 

  class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 

	// Write your code here

    Node *merge(Node *root, Node *head){
    if (!head)
        return root;
    if (!root)
        return head;
    Node *res;
    if (root->data < head->data)
    {
        res = root;
        res->child = merge(res->child, head);
    }
    else
    {
        res = head;
        res->child = merge(root, res->child);
    }
    return res;
}

Node* flattenLinkedList(Node *root){
    if (root == nullptr)
    return root;
    Node *head = flattenLinkedList(root->next);
    return merge(root, head);
}

int main(){


    return 0; 
}