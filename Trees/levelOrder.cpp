#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Proper Level Order Traversal (BFS)
void levelOrder(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    node* head = new node(11);
    node* two = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(52);

    head->left = two;
    head->right = p3;
    p3->left = p4;

    levelOrder(head);

    return 0;
}