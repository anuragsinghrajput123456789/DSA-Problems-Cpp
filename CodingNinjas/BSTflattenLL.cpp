#include <bits/stdc++.h>

/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inOrder(TreeNode<int>* root, std::vector<int>& ans) {
   if (root == NULL) {
       return;
   }
   inOrder(root->left, ans);
   ans.push_back(root->data);
   inOrder(root->right, ans);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    if (root == NULL) {
        return NULL; // Handle empty tree case
    }

    std::vector<int> ans;
    // store inorder --> sorted values
    inOrder(root, ans);

    if (ans.empty()) {
        return NULL; // Should not happen if root is not NULL, but good for robustness
    }

    // assigning the new node to the starting part of the inOrder vector
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);

    TreeNode<int>* curr = newRoot;

    // Build the flattened list
    for (int i = 1; i < ans.size(); i++) {
        TreeNode<int>* temp = new TreeNode<int>(ans[i]);

        curr->left = NULL;     // Left child should always be NULL
        curr->right = temp;    // Right child points to the next node
        curr = curr->right;    // Move curr to the newly added node
    }

    // The last node's left and right pointers are already NULL by default
    // or set to NULL in the loop. No need for explicit step 3.

    return newRoot;
}