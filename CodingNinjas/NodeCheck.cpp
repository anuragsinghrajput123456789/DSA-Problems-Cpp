#include<bits/stdc++.h>
using namespace std; 
    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root == nullptr)return false; 
    if(root->data == x)return true; 

    bool leftcheck = isNodePresent(root->left,x);
    if(leftcheck)return true; 
    return isNodePresent(root->right,x);
}

int main(){

    return 0; 
}