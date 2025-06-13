#include<bits/stdc++.h>
using namespace std; 


class Node {
    int data; 
    Node* left; 
    Node* right; 

  public:
  
    Node* solve(Node* root, int &k, int node) {
        // Base case: if the current node is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // If we found the node, return the node
        if (root->data == node) {
            return root;
        }

        // Search in the left and right subtrees
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        // If the node was found in the left subtree
        if (leftAns != nullptr && rightAns == nullptr) {
            k--;  // We're going up the tree

            // If we have reached the kth ancestor
            if (k == 0) {
                return root;
            }

            // Otherwise, return the left answer if k is still greater than 0
            return leftAns;
        }
        
        // If the node was found in the right subtree
        if (leftAns == nullptr && rightAns != nullptr) {
            k--;  // We're going up the tree

            // If we have reached the kth ancestor
            if (k == 0) {
                return root;
            }

            // Otherwise, return the right answer if k is still greater than 0
            return rightAns;
        }
        
        // If both left and right answers are not null, return the non-null result
        if (leftAns != nullptr && rightAns != nullptr) {
            return root;
        }

        // Otherwise, return null if the node wasn't found in either subtree
        return nullptr;
    }
  
    int kthAncestor(Node *root, int k, int node) {
        // Call the solve function
        Node* ans = solve(root, k, node);

        // If no ancestor is found, return -1
        if (ans == nullptr || k > 0) {
            return -1;
        }

        // Otherwise, return the kth ancestor
        return ans->data;
    }
};


int main(){


    return 0; 
}