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

TreeNode<int>* mergeBST(TreeNode<int>* root1,
                        TreeNode<int>* root2) {

    // Step 1: BST -> DLL
    TreeNode<int>* head1 = nullptr;
    TreeNode<int>* head2 = nullptr;

    bstToSortedDll(root1, head1);
    bstToSortedDll(root2, head2);

    // Step 2: Merge DLLs
    TreeNode<int>* mergedHead =
        mergeLL(head1, head2);

    // Step 3: Count nodes
    int totalNodes =
        countNodes(mergedHead);

    // Step 4: DLL -> BST
    return sortedLLToBST(
        mergedHead,
        totalNodes
    );
}