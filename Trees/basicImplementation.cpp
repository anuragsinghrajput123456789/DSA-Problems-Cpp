#include<bits/stdc++.h>
#include<vector>
using namespace std;

class node{
  public: 
   int data; 
   node* left; 
   node* right; 
   
   node(int data){
     this->data = data; 
     this->left = nullptr; 
     this->right = nullptr; 
   }
};

void traverseLeft(Node* root,vector<int> &ans){
      //base case
      if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
          return ;
      }
      
      ans.push_back(root->data); 
      if(root->left){
        traverseLeft(root->left);   
      }
      else{
          traverseLeft(root->right);
      }
}

void traverseLeft(Node* root, std::vector<int> &ans){
        // Base case: if root is null or it's a leaf node, stop.
        // Leaf nodes are handled by traverseLeaf.
        if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
            return ;
        }
        
        // Add current node's data to the result
        ans.push_back(root->data); 
        
        // Prioritize left child for left boundary
        if(root->left){
            traverseLeft(root->left, ans); // Pass ans by reference
        }
        else{
            // If no left child, go to the right child to continue the boundary
            traverseLeft(root->right, ans); // Pass ans by reference
        }
    }
    
    // Function to traverse all leaf nodes
    void traverseLeaf(Node* root, std::vector<int> &ans){
        // Base case: if root is null, stop.
        if(root == nullptr){
            return ; 
        }
        
        // If it's a leaf node, add its data to the result
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
        }
        
        // Recursively traverse left and right subtrees
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    // Function to traverse the right boundary (excluding leaf nodes) in reverse order
    void traverseRight(Node* root, std::vector<int> &ans){
        // Base case: if root is null or it's a leaf node, stop.
        // Leaf nodes are handled by traverseLeaf.
        if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
            return ;
        }
        
        // Prioritize right child for right boundary
        if(root->right){
            traverseRight(root->right, ans); // Pass ans by reference
        }
        else{
            // If no right child, go to the left child to continue the boundary
            traverseRight(root->left, ans); // Pass ans by reference
        }
        
        // Add current node's data to the result AFTER the recursive call returns.
        // This ensures elements are added in reverse order (bottom-up).
        ans.push_back(root->data);
    }
    


int main(){
  
  
    
  
  
  return 0; 
}
