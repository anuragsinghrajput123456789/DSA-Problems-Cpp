#include <bits/stdc++.h>  
#include<vector>
using namespace std; 
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


void inOrder(TreeNode<int>* root,vector<int>&ans){
  if(root == NULL)return ; 

  inOrder(root->left,ans);
  ans.push_back(root->data);
  inOrder(root->right,ans);
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> ans; 

    inOrder(root,ans);
    
    //Declaring the starting node of the from the ans;  
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);

    int n = ans.size();
    
    TreeNode<int> *curr = newRoot;

   
   for(int i=1; i<n; i++){
       TreeNode<int>*temp = new TreeNode<int>(ans[i]);

       curr->left = NULL; 
       curr->right = temp; 
       curr = temp;
   }

  //last node
  curr->left = NULL; 
  curr->right = NULL; 
  return newRoot; 

}


int main(){


    return 0; 
}