#include <bits/stdc++.h> 
using namespace std; 
    class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode<int> *left;
        BinaryTreeNode<int> *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int solve(BinaryTreeNode<int> * root,int &i,int k){
     // base case
     if(root == nullptr)return -1;

     int left = solve(root->left,i,k);
     
     if(left != -1)return left; 
     
     i++;
     if(i == k)return root->data;
     
     return solve(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    int ans = solve(root,i,k); 
    return ans; 
}
int main(){


    return 0; 
}