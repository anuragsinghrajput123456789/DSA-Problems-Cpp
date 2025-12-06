#include<bits/stdc++.h>
using namespace std; 
struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution {
  public:
     Node* solve(Node* root, int &k, int node) {
        if(root == nullptr) return nullptr;

        if(root->data == node) return root;

        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        // Node found in left subtree
        if(leftAns != nullptr) {
            k--;
            if(k == 0) {
                return root;
            }
            return leftAns;
        }

        // Node found in right subtree
        if(rightAns != nullptr) {
            k--;
            if(k == 0) {
                return root;
            }
            return rightAns;
        }

        // node not found in either subtree
        return nullptr;
    }
    
     int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);

        // if ans is the node itself or null, no ancestor exists
        if(ans == nullptr || ans->data == node) return -1;

        return ans->data;
    }
};
