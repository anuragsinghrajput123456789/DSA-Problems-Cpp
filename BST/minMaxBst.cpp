#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Bring the entire std namespace into scope to avoid prefixing with std::
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

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

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void inOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool findInBst(node *root, int data)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    if (data < root->data)
    {
        return findInBst(root->left, data);
    }
    else
    {
        return findInBst(root->right, data);
    }
}

int minInBst(node *root)
{
    node *temp = root;

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxInBst(node *root)
{
    node *temp = root;

    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->data;
}

int main()
{
    node *root = nullptr;

    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 35);
    root = insertIntoBST(root, 75);

    cout << "In-order traversal (should be sorted): ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    int searchValue1 = 40;
    if (findInBst(root, searchValue1))
    {
        cout << searchValue1 << " found in BST." << endl;
    }
    else
    {
        cout << searchValue1 << " not found in BST." << endl;
    }

    int searchValue2 = 99;
    if (findInBst(root, searchValue2))
    {
        cout << searchValue2 << " found in BST." << endl;
    }
    else
    {
        cout << searchValue2 << " not found in BST." << endl;
    }

    cout << minInBst(root) << endl;
    cout << maxInBst(root) << endl;

    return 0;
}
