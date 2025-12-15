#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void preorder(node* root){
    if(root == nullptr) return;
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

void levelOrder(node* root){
    if(root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << temp->data << endl;

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int minVal(node* root){
    node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp->data;
}

node* deletefromBst(node* root, int data){
    if(root == nullptr) return root;

    if(root->data == data){

        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // 1 child (left)
        if(root->left != nullptr && root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child (right)
        if(root->left == nullptr && root->right != nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        int mini = minVal(root->right);
        root->data = mini;
        root->right = deletefromBst(root->right, mini);
        return root;
    }

    if(data < root->data){
        root->left = deletefromBst(root->left, data);
    } else {
        root->right = deletefromBst(root->right, data);
    }

    return root;
}

int main(){
    node* root = new node(20);
    root->left = new node(10);
    root->right = new node(30);
    root->left->left = new node(5);
    root->left->right = new node(15);

    inorder(root);
    cout << endl;

    root = deletefromBst(root, 10);
    inorder(root);

    return 0;
}
