#include<bits/stdc++.h>

using namespace std;

class Node{
    public: 
    int data ;
    Node* right; 
    Node* left; 
    Node(int data){
        this->data = data; 
        right = left = nullptr;
    }
};

class Solution {
  public:
    Node* solve(Node* root, int &k, int node){
        if(root == nullptr) return nullptr;

        if(root->data == node) return root;

        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        // logic after backtracking

        // node present on left side only
        if(leftAns != nullptr && rightAns == nullptr){
            k--;

            if(k <= 0){
                k = INT_MAX;      // lock answer
                return root;
            }

            return leftAns;
        }

        // node present on right side only
        if(rightAns != nullptr && leftAns == nullptr){
            k--;

            if(k <= 0){
                k = INT_MAX;      // lock answer
                return root;
            }

            return rightAns;
        }

        return nullptr;
    }

    int kthAncestor(Node *root, int k, int node){
        Node* ans = solve(root, k, node);

        if(ans == nullptr || ans->data == node) return -1;

        return ans->data;
    }
};
