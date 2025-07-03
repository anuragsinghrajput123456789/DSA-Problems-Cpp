
BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int max, int &i) {
    if (i >= preorder.size()) return NULL;

    if (preorder[i] < mini || preorder[i] > max) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i]);
    i++;  // Move to the next element

    root->left = solve(preorder, mini, root->data - 1, i);
    root->right = solve(preorder, root->data + 1, max, i);
    
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preorder, mini, max, i);
}
