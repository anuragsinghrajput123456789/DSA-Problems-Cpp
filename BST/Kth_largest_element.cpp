#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int solve(TreeNode<int>*root,int &i,int k){
  if(root == nullptr)return -1; 

  int right = solve(root->right,i,k);

  //processing operation in this...
  if(right != -1)return right;
  i++;
  if(i == k)return root->data; 

  return solve(root->left,i,k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int i = 0;
    int ans = solve(root,i,k);
    return ans; 
}
