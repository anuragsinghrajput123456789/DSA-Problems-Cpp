#include<bits/stdc++.h>
using namespace std; 

int inOrder(BinaryTreeNode<int> *root, int &count){
  //base case
  if(root == nullptr){
      return -1; 
  }

  inOrder(root->left,count);

  //leaf node count kar rahe hai abb
  if(root->left == nullptr && root->right == nullptr){
       count++; 
  } 
  inOrder(root->right,count); 
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt = 0; 
 inOrder(root,cnt);
 return cnt;  
}

int main(){

    return 0 ;
}