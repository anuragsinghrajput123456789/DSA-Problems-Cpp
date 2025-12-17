#include <bits/stdc++.h> 
using namespace std; 
class BinaryTreeNode {
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

void inorder(BinaryTreeNode<int>*root,vector<int> &ino){
   if(root == nullptr)return ; 
   inorder(root->left,ino);
   ino.push_back(root->data);
   inorder(root->right,ino);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
  vector<int> inorderVal;
  //getting inorder of bst || sorted values to find sum
  inorder(root,inorderVal);
  int i = 0 , j = inorderVal.size() - 1;
  
  //applying two pointer approach to find the sum == target
  while(i < j){
      int sum = inorderVal[i] + inorderVal[j];
      if(sum == target)return true; 
      else if(sum > target)j--;
      else{
        i++;
      }
  }
  return false;
}

int main(){
    


    return 0; 
}