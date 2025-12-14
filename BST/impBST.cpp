
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// descending inorder
void inOrder(node* root) {
    if (!root) return;
    inOrder(root->right);
    cout << root->data << " ";
    inOrder(root->left);
}

void inOrder(node* root){
  if(!root) return;
  inOrder(root->left);
  cout << root->data << endl; 
  inOrder(root->right);
}

void preOrder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->right);
    preOrder(root->left);
}

void postOrder(node* root) {
    if (!root) return;
    postOrder(root->right);
    postOrder(root->left);
    cout << root->data << " ";
}

node* insertBst(node* root, int data) {
    if (!root) return new node(data);

    if (data < root->data)
        root->left = insertBst(root->left, data);
    else
        root->right = insertBst(root->right, data);

    return root;
}

void levelOrder(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main() {
    int arr[] = {8, 0, 9, 4, 6, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    node* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = insertBst(root, arr[i]);
    }

    cout << "Inorder: ";
    inOrder(root);

    cout << "\nPreorder: ";
    preOrder(root);

    cout << "\nPostorder: ";
    postOrder(root);

    cout << "\nLevel order: ";
    levelOrder(root);

    return 0;
}
