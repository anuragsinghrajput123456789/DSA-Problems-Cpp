#include<bits/stdc++.h>
using namespace std; 

class node{
  public: 
  int data; 
  node* left; 
  node* right; 
  
  node(int data){
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};


node* insertIntoBst(node* root,int data){
  //base case
  if(root == NULL){
    root = new node(data);
    return root;
  } 
  if(data > root->data) root->right = insertIntoBst(root->right,data);

  else{
    root->left = insertIntoBst(root->left,data);
  }
  return root;
}


void inOrder(node* root,vector<int>*root){
  
}

int main(){
  
  
  
  
  
  return 0; 
}