#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

vector<int> levelOrder(node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        ans.push_back(curr->data);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return ans;
}

bool isBSTUtil(node* root, int minVal, int maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBst(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    node* p1 = new node(40);
    node* p2 = new node(30);
    node* p3 = new node(60);
    node* p4 = new node(20);
    node* p5 = new node(35);
    node* p6 = new node(50);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;

    cout << "Preorder: ";
    preOrder(p1);
    cout << "\nInorder: ";
    inOrder(p1);
    cout << "\nPostorder: ";
    postOrder(p1);
    cout << "\nLevel Order: ";
    vector<int> result = levelOrder(p1);
    for (int i : result) cout << i << " ";

    cout << "\nIs BST: " << (isBst(p1) ? "Yes" : "No") << endl;

    return 0;
}
