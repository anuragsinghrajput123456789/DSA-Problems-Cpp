#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n) {

    if (n <= 0 || head == nullptr)
        return nullptr;

    TreeNode<int>* leftSubtree =
        sortedLLToBST(head, n / 2);

    TreeNode<int>* root = head;

    root->left = leftSubtree;

    head = head->right;

    root->right =
        sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

int main(){



    return 0; 
}