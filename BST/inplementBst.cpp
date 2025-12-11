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

// Traversals
void inOrder(node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

// Insert into BST
node* insertIntoBst(node* root, int data) {
    if (root == nullptr) {
        root = new node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertIntoBst(root->left, data);
    } else {
        root->right = insertIntoBst(root->right, data);
    }
    return root;
}

// Build BST from user input until -1
void takeInput(node*& root) {
    int data;
    while (cin >> data && data != -1) {
        root = insertIntoBst(root, data);
    }
}

int main() {
    node* root = nullptr;

    cout << "Enter values for BST. Enter -1 to stop: ";
    takeInput(root);

    cout << "InOrder: ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;

    cout << "Level Order:\n";
    levelOrder(root);

    return 0;
}
