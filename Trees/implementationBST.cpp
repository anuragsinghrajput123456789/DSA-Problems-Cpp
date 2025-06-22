#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *insertIntoBST(node *root, int data)
{
    if (root == nullptr)
    {
        return new node(data);
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

// Inorder traversal to display the tree
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(11);

    // Sample data to insert into BST
    vector<int> values = {11, 5, 15, 3, 7, 13, 17, -1}; // -1 to end input

    for (int val : values)
    {
        if (val == -1)
            break;
        root = insertIntoBST(root, val);
    }

    cout << "Inorder Traversal (Sorted): ";
    inorder(root);
    cout << endl;

    return 0;
}
