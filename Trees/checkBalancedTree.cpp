#include<bits/stdc++.h>
using namespace std; 

class Node {
    int data; 
    Node* left; 
    Node* right; 
  public: 
   int height(Node* root){
       //base case
       if(root == nullptr){
           return 0;
       }
       int l = height(root->left);
       int r = height(root->right);
       int ans = max(l,r) + 1;
       return ans; 
   }

  public:
    bool isBalanced(Node* root) {
      //base case
      if(root == nullptr){
          return true; 
      }
      
      bool left = isBalanced(root->left);
      bool right = isBalanced(root->right);
      
      bool diff = abs(height(root->left) - height(root->right)) <= 1; 
      
      if(left && right && diff){
          return true; 
      }
      return false; 
    }
};

int main(){


    return 0; 
}