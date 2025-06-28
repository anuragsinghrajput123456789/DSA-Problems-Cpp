#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isBst(BinaryTreeNode<int> *root, int min,int max){
     //base case
     if(root == NULL){
       return true; 
     }

     if(root->data <= min || root->data >= max){
       return false; 
     }
     return isBst(root->left,min,root->data) && isBst(root->right,root->data,max);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
   return isBst(root,INT_MIN,INT_MAX);
   
}