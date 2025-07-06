class Info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;

    Info(int maxVal, int minVal, bool isB, int s) {
        maxi = maxVal;
        mini = minVal;
        isBST = isB;
        size = s;
    }
};

// Corrected: Removed <int>
Info solve(TreeNode* root, int &maxSize) {
    if (root == NULL) {
        return Info(INT_MIN, INT_MAX, true, 0);
    }

    Info leftInfo = solve(root->left, maxSize);
    Info rightInfo = solve(root->right, maxSize);

    Info currNodeInfo(0, 0, false, 0);

    currNodeInfo.size = leftInfo.size + rightInfo.size + 1;

    currNodeInfo.maxi = max(root->data, rightInfo.maxi);
    currNodeInfo.mini = min(root->data, leftInfo.mini);

    if (leftInfo.isBST && rightInfo.isBST &&
        root->data > leftInfo.maxi && root->data < rightInfo.mini) {
        currNodeInfo.isBST = true;
    } else {
        currNodeInfo.isBST = false;
    }

    if (currNodeInfo.isBST) {
        maxSize = max(maxSize, currNodeInfo.size);
    }

    return currNodeInfo;
}

// Corrected: Removed <int>
int largestBST(TreeNode* root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}
