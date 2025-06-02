#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Tree Node (assuming this structure is provided or defined elsewhere)

class Node

{

    int data;
    Node *left;
    Node *right;

public:
    // Function to traverse the left boundary (excluding leaf nodes)
    void traverseLeft(Node *root, std::vector<int> &ans)
    {
        // Base case: if root is null or it's a leaf node, stop.
        // Leaf nodes are handled by traverseLeaf.
        if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        // Add current node's data to the result
        ans.push_back(root->data);

        // Prioritize left child for left boundary
        if (root->left)
        {
            traverseLeft(root->left, ans); // Pass ans by reference
        }
        else
        {
            // If no left child, go to the right child to continue the boundary
            traverseLeft(root->right, ans); // Pass ans by reference
        }
    }

    // Function to traverse all leaf nodes
    void traverseLeaf(Node *root, std::vector<int> &ans)
    {
        // Base case: if root is null, stop.
        if (root == nullptr)
        {
            return;
        }

        // If it's a leaf node, add its data to the result
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
        }

        // Recursively traverse left and right subtrees
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // Function to traverse the right boundary (excluding leaf nodes) in reverse order
    void traverseRight(Node *root, std::vector<int> &ans)
    {
        // Base case: if root is null or it's a leaf node, stop.
        // Leaf nodes are handled by traverseLeaf.
        if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        // Prioritize right child for right boundary
        if (root->right)
        {
            traverseRight(root->right, ans); // Pass ans by reference
        }
        else
        {
            // If no right child, go to the left child to continue the boundary
            traverseRight(root->left, ans); // Pass ans by reference
        }

        // Add current node's data to the result AFTER the recursive call returns.
        // This ensures elements are added in reverse order (bottom-up).
        ans.push_back(root->data);
    }

    // Main function for boundary traversal
    vector<int> boundaryTraversal(Node *root)
    {
        std::vector<int> ans;

        // Handle empty tree
        if (root == nullptr)
        {
            return ans;
        }

        // Add the root node (it's part of the boundary unless it's the only node)
        ans.push_back(root->data);

        // Traverse the left boundary, starting from root's left child
        traverseLeft(root->left, ans);

        // Traverse leaf nodes:
        // First, traverse leaves in the left subtree
        traverseLeaf(root->left, ans);
        // Then, traverse leaves in the right subtree
        traverseLeaf(root->right, ans);

        // Traverse the right boundary, starting from root's right child
        // Note: The right boundary nodes are added in reverse order by traverseRight
        traverseRight(root->right, ans);

        return ans;
    }
};