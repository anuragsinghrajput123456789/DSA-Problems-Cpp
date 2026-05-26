#include<bits/stdc++.h>
using namespace std; 
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *temp = root;

    int pre = -1;
    int suc = -1;

    // search key
    while (temp != NULL && temp->data != key)
    {
        if (temp->data > key)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }

   //edge case if key was not found there then return 
    if (temp == NULL)return {pre, suc};

    // predecessor
    TreeNode *leftTree = temp->left;

    // maximum value in left subtree
    while (leftTree != NULL)
    {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    // successor
    TreeNode *rightTree = temp->right;

    // minimum value in right subtree
    while (rightTree != NULL)
    {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pre, suc};
}