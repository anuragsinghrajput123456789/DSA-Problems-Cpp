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

void inOrderPrint(node* root){
  //base case
  if(root == NULL)return ; 
  inOrderPrint(root->left);
  cout << "--" <<  root->data;
  inOrderPrint(root->right);
}

void preOrder(node* root){
  //base case
  if(root == NULL)return ; 
  cout << "--" <<  root->data;
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(node* root){
  //base case
  if(root == NULL)return ; 
  
  postOrder(root->left);
  postOrder(root->right);
  cout << "--" <<  root->data;
}

void inOrder(node* root,vector<int>&ans){
  if(root == nullptr)return ;
  inOrder(root->left,ans);
  ans.push_back(root->data);
  inOrder(root->right,ans);
}

int heightofTree(node* root){
  //base
  if(root == nullptr)return -1;
  
  int l = heightofTree(root->left);
  int r =  heightofTree(root->right);
  int finalheight = max(l,r) + 1;
  return finalheight; 
}

int noOfnodes(node* root){
  //base case
  if(root == nullptr)return -1; 
  
  int l = noOfnodes(root->left);
  int r = noOfnodes(root->right);
  int final = l+r+1; 
  return final; 
}

int sumOfnodes(node* root){
  //base case
  if(root == nullptr)return -1;
  
  int r = sumOfnodes(root->right);
  int l = sumOfnodes(root->left);
  return l+r+(root->data); 
}

bool isBst(node* root){
  if(root == nullptr)return false; 
  vector<int> ans;
  inOrder(root,ans);
  int n = noOfnodes(root);
  
   for(int i=0; i<n-1; i++){
     if(ans[i] >= ans[i+1]){
       return false; 
     }
   }
  return true;
}

int main(){

  node* p1 = new node(44);
  node* p2 = new node(22);
  node* p3= new node(66);
  node* p4 = new node(11);
  node* p5 = new node(33);
  node* p6 = new node(55);

  
  p1->left = p2; 
  p1->right = p3; 
  p2->left=  p4; 
  p2->right = p5; 
  p3->left= p6; 
  
  
  inOrderPrint(p1);
  cout << endl; 
  
  cout << "It is BSt : " << (isBst(p1) ? "true" : "flase");
  
  
  
  return 0; 
}
