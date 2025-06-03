#include<bits/stdc++.h>
using namespace std;

class node{
  public: 
  
  int data; 
  node* right; 
  node* left; 
  
  node(int data){
    this->data = data; 
    this->right = nullptr; 
    this->left = nullptr; 
  }
};


void inOrder(node* root){
  if(root == nullptr){
    return ; 
  }
  
  inOrder(root->left);
  cout << root->data << endl; 
  inOrder(root->right);
}


void preOrder(node* root){
  if(root == nullptr){
    return ; 
  }
  
  cout << root->data << endl; 
  preOrder(root->left);
  preOrder(root->right);
}

int isBst(node* root){
  node* prev = nullptr; 
  
  if(root != nullptr){
     if(!isBst(root->left)){
       return 0; 
     }
     if(prev != nullptr && root->data <= prev->data){
       return 0; 
     }
     prev = root; 
     return isBst(root->right);
     
  }
  else{
    return 1;
  }
}

int main(){
  
  node* p = new node(5);
  node* p1 = new node(3);
  node* p2 = new node(6);
  node* p3 = new node(1);
  node* p4 = new node(4);
  


  p->left = p1; 
  p->right = p2; 
  p1->left = p3; 
  p1->right = p4;
  
  
  // inOrder(p);
   cout << isBst(p);
  
  // preOrder(p);

  
  return 0; 
}