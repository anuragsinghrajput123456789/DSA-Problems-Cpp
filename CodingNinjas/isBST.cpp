#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

/* ---------- Method 1: Inorder based ---------- */

bool inorderCheck(BinaryTreeNode<int>* root, int &prev){
    if(!root) return true;

    if(!inorderCheck(root->left, prev)) return false;

    if(root->data <= prev) return false;
    prev = root->data;

    return inorderCheck(root->right, prev);
}

bool validateBST(BinaryTreeNode<int>* root){
    int prev = INT_MIN;
    return inorderCheck(root, prev);
}

/* ---------- Method 2: Range based ---------- */

bool isBSTUtil(BinaryTreeNode<int>* root, int low, int high){
    if(!root) return true;

    if(root->data <= low || root->data >= high) return false;

    return isBSTUtil(root->left, low, root->data) &&
           isBSTUtil(root->right, root->data, high);
}

bool validateBSTRange(BinaryTreeNode<int>* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* ---------- Driver code ---------- */

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(20);
    root->left = new BinaryTreeNode<int>(10);
    root->right = new BinaryTreeNode<int>(30);
    root->left->left = new BinaryTreeNode<int>(5);
    root->left->right = new BinaryTreeNode<int>(15);

    cout << validateBST(root) << endl;
    cout << validateBSTRange(root) << endl;

    return 0;
}
