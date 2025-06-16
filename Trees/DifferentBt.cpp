class Solution {
public:
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTreeHelper(vector<int>& preorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap[rootVal];

        root->left = buildTreeHelper(preorder, preIndex, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTreeHelper(preorder, preIndex, 0, n - 1);
    }
};
