

/* Helper function to do inorder traversal */
void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& ans) {
    if (root == NULL) return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

/* Main function to check if it's a BST */
bool validateBST(BinaryTreeNode<int>* root) {
    vector<int> ans;
    inorderTraversal(root, ans);

    // Check if the inorder list is strictly increasing
    for (int i = 1; i < ans.size(); i++) {
        if ([i] <= ans[i - 1]) {
            return false;
        }
    }

    return true;
}
