#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key){
    if(!root) return NULL;

    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }
    else{
        // 0 or 1 child
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        // 2 children
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    inorder(root);
    cout << endl;

    root = deleteBST(root, 10);

    inorder(root);
}
