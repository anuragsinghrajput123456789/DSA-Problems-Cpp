// Definition of the Node class
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int findPosition(vector<int> &in, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }

    Node *solve(vector<int> &in, vector<int> &pre, int &index, int inorderStart, int inorderEnd, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
        {
            return nullptr;
        }

        int element = pre[index++];
        Node *root = new Node(element);
        int position = findPosition(in, element, n);

        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        int preOrderIndex = 0;
        return solve(inorder, preorder, preOrderIndex, 0, n - 1, n);
    }
};

int main()
{

    return 0;
}