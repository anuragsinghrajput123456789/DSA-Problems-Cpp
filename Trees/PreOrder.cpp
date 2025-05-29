#include<bits/stdc++.h>
using namespace std; 

class Node{
  public:
  int data; 
  Node* left;
  Node* right; 
  Node(int data){
      this->data = data; 
      this->left = nullptr; 
      this->right = nullptr;
  }
    void solve(Node* root, vector<int> &ans){
        if(root == NULL) return;
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        // write code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main(){


    return 0; 
}