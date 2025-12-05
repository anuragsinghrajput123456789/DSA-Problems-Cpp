#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root == nullptr)return nullptr; 
        if(root->data == n1 || root->data == n2)return root;
        
        Node* leftAns = lca(root->left,n1,n2);
        Node* rightAns = lca(root->right,n1,n2);
        
        if(leftAns != nullptr && rightAns != nullptr)return root;
        
        else if(leftAns != nullptr && rightAns == nullptr)return leftAns;
        
        else if(leftAns == nullptr && rightAns != nullptr)return rightAns;
        
        else{
            return nullptr; 
        }
    }
};

int main(){


    

    return 0; 
}