#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
private:
    // Count total number of nodes in the tree
    int countNodes(Node *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Check if the tree is Complete Binary Tree (CBT)
    // Using 0-based indexing for nodes
    bool isCBT(Node *root, int index, int totalNodes)
    {
        // Base case: null node is valid
        if (root == nullptr)
        {
            return true;
        }

        // If index has gone beyond total nodes → violation
        if (index >= totalNodes)
        {
            return false;
        }

        // Recursively check left and right children
        // Left child index = 2*index + 1
        // Right child index = 2*index + 2
        return isCBT(root->left, 2 * index + 1, totalNodes) &&
               isCBT(root->right, 2 * index + 2, totalNodes);
    }

    // Check Max-Heap property (parent >= children)
    bool isMaxHeapOrder(Node *root)
    {
        // Leaf node or null → valid
        if (root == nullptr)
        {
            return true;
        }

        // Check left child
        if (root->left != nullptr && root->data < root->left->data)
        {
            return false;
        }

        // Check right child
        if (root->right != nullptr && root->data < root->right->data)
        {
            return false;
        }

        // Recursively check both subtrees
        return isMaxHeapOrder(root->left) && isMaxHeapOrder(root->right);
    }

public:
    bool isHeap(Node *tree)
    {
        if (tree == nullptr)
            return true; // empty tree can be considered heap

        int totalNodes = countNodes(tree);

        // 0-based indexing starts with root at index 0
        bool complete = isCBT(tree, 0, totalNodes);
        bool heapOrder = isMaxHeapOrder(tree);

        return complete && heapOrder;
    }
};