/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int solveSmallest(BinaryTreeNode<int>* root, int &i, int k) {
    if (root == NULL) {
        return -1;
    }

    int leftResult = solveSmallest(root->left, i, k);

    if (leftResult != -1) {
        return leftResult;
    }

    i++;
    if (i == k) {
        return root->data;
    }

    return solveSmallest(root->right, i, k);
}

int solveLargest(BinaryTreeNode<int>* root, int &i, int k) {
    if (root == NULL) {
        return -1;
    }

    int rightResult = solveLargest(root->right, i, k);
    
    if (rightResult != -1) {
        return rightResult;
    }

    i++;
    if (i == k) {
        return root->data;
    }

    return solveLargest(root->left, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    int ans = solveSmallest(root, i, k);
    return ans; 
}

int kthLargest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    int ans = solveLargest(root, i, k);
    return ans;
}
