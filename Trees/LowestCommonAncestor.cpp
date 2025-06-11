/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

#include<bits/stdc++.h>
using namespace std;
class Node {
    
    int data; 
    Node* left; 
    Node* right; 

  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
    // basse case
    if(root == nullptr){
        return nullptr; 
    }
    
    if(root->data == n1 || root->data == n2){
        return root; 
    }
    
    Node* leftAns = lca(root->left, n1,n2);
    Node* rightAns = lca(root->right, n1,n2);
    
    if(leftAns != nullptr && rightAns != nullptr){
        return root; 
    }
    else if(leftAns != nullptr && rightAns == nullptr){
        return leftAns; 
    }
    else if(leftAns == nullptr && rightAns != nullptr){
        return rightAns; 
    }
    else{
        return nullptr; 
    }
 }
};

int main(){





    return 0; 
}