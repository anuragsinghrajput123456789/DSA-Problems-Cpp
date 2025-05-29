#include<bits/stdc++.h>
using namespace std; 

class Node{
   int data; 
   Node* right; 
   Node* left; 
  public:
  void solve(Node* root, vector<int> &ans){
      if(root == NULL)return;
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->data);
  }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int>ans; 
        solve(root,ans);
        return ans; 
    }
};

int main(){

    return 0;
}