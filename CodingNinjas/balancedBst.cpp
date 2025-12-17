#include<bits/stdc++.h>
using namespace std; 
    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inOrder(TreeNode<int> *root,vector<int> &ans){
   //base case
   if(root == NULL)return ; 
   
   inOrder(root->left,ans);
   ans.push_back(root->data);
   inOrder(root->right,ans);
}

TreeNode<int>* inOrderToBst(int s,int e,vector<int> ans){
  //base case
  if(s > e)return NULL; 

  int mid = s + (e - s)/2;

  TreeNode<int>*root = new TreeNode<int>(ans[mid]);
  root->left = inOrderToBst(s,mid-1,ans);
  root->right = inOrderToBst(mid+1,e,ans);

  return root;

}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
   

  vector<int> ans; 
  inOrder(root,ans);
  int n = ans.size();
  return inOrderToBst(0,n-1,ans);

}
