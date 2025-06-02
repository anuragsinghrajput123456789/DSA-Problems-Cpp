#include<bits/stdc++.h>
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

// void traverseLeft(Node* root,vector<int> &ans){
//       //base case
//       if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
//           return ;
//       }
      
//       ans.push_back(root->data); 
//       if(root->left){
//         traverseLeft(root->left);   
//       }
//       else{
//           traverseLeft(root->right);
//       }
// }

// void traverseLeft(Node* root, std::vector<int> &ans){
//         // Base case: if root is null or it's a leaf node, stop.
//         // Leaf nodes are handled by traverseLeaf.
//         if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
//             return ;
//         }
        
//         // Add current node's data to the result
//         ans.push_back(root->data); 
        
//         // Prioritize left child for left boundary
//         if(root->left){
//             traverseLeft(root->left, ans); // Pass ans by reference
//         }
//         else{
//             // If no left child, go to the right child to continue the boundary
//             traverseLeft(root->right, ans); // Pass ans by reference
//         }
//     }
    
//     // Function to traverse all leaf nodes
// void traverseLeaf(Node* root, std::vector<int> &ans){
//         // Base case: if root is null, stop.
//         if(root == nullptr){
//             return ; 
//         }
        
//         // If it's a leaf node, add its data to the result
//         if(root->left == nullptr && root->right == nullptr){
//             ans.push_back(root->data);
//         }
        
//         // Recursively traverse left and right subtrees
//         traverseLeaf(root->left, ans);
//         traverseLeaf(root->right, ans);
//     }
    
//     // Function to traverse the right boundary (excluding leaf nodes) in reverse order
// void traverseRight(Node* root, std::vector<int> &ans){
//         // Base case: if root is null or it's a leaf node, stop.
//         // Leaf nodes are handled by traverseLeaf.
//         if((root == nullptr) || (root->left == nullptr && root->right == nullptr)){
//             return ;
//         }
        
//         // Prioritize right child for right boundary
//         if(root->right){
//             traverseRight(root->right, ans); // Pass ans by reference
//         }
//         else{
//             // If no right child, go to the left child to continue the boundary
//             traverseRight(root->left, ans); // Pass ans by reference
//         }
        
//         // Add current node's data to the result AFTER the recursive call returns.
//         // This ensures elements are added in reverse order (bottom-up).
//         ans.push_back(root->data);
//     }
 
vector<int> preOrderst(node* tree,vector<int> &ans){
  // base case
  if(tree == nullptr){
    return ans; 
  }
  ans.push_back(tree->data);
  preOrderst(tree->left,ans);
  preOrderst(tree->right,ans);
  return ans; 
}

void preOrder(node* tree){
  // base case
  if(tree == nullptr){
    return ; 
  }
  
  cout << tree->data << endl;
  preOrder(tree->left);
  preOrder(tree->right);
}   


int main(){
  node* first = new node(11);
  node* p1 = new node(22);
  node* p2 = new node(33);
  node* p3 = new node(44);
  node* p4 = new node(55);
  node* p5 = new node(66);
  node* p6 = new node(77);

  
  vector<int>ans;
    
  first->left = p1; 
  first->right = p2; 
  p2->left = p3; 
  p2->right = p4; 
  p3->left = p6; 
  p3->right = p5; 
  
  // preOrder(first); 
  
  preOrderst(first,ans);
  
  for(auto i : ans){
    cout << i << endl; 
  }
    
  
  
  return 0; 
}

int main(){

  return 0; 
}