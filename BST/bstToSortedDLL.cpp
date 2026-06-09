#include<bits/stdc++.h>
using namespace std; 

// BST -> Sorted Doubly Linked List
void bstToSortedDll(TreeNode<int>* root, TreeNode<int>* &head) {
    if (root == nullptr)
        return;

    bstToSortedDll(root->right, head);

    root->right = head;

    if (head != nullptr)
        head->left = root;

    head = root;

    bstToSortedDll(root->left, head);
}

int main(){



    return 0; 
}