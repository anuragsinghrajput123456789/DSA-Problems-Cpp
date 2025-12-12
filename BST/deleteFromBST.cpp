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

// Inorder
void inOrder(node* p1){
    if(p1 == nullptr) return;
    inOrder(p1->left);
    cout << p1->data << " ";
    inOrder(p1->right);
}

// Preorder
void preOrder(node* p1){
    if(p1 == nullptr) return;
    cout << p1->data << " ";
    preOrder(p1->left);
    preOrder(p1->right);
}

// Postorder
void postOrder(node* p1){
    if(p1 == nullptr) return;
    postOrder(p1->left);
    postOrder(p1->right);
    cout << p1->data << " ";
}

// Level Order
void levelOrder(node* p1){
    if(p1 == nullptr) return;

    queue<node*> q;
    q.push(p1);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
}

// Morris Inorder
void morrisInorder(node* root){
    node* curr = root;

    while(curr != nullptr){
        if(curr->left == nullptr){
            cout << curr->data << " ";
            curr = curr->right;
        } 
        else {
            node* pred = curr->left;
            while(pred->right != nullptr && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            } 
            else {
                pred->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

// Morris Preorder
void morrisPreorder(node* root){
    node* curr = root;

    while(curr != nullptr){
        if(curr->left == nullptr){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            node* pred = curr->left;
            while(pred->right != nullptr && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == nullptr){
                cout << curr->data << " ";
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

// Insert
node* binaryTree(node* p1, int data){
    if(p1 == nullptr){
        return new node(data);
    }
    if(data < p1->data){
        p1->left = binaryTree(p1->left, data);
    } 
    else {
        p1->right = binaryTree(p1->right, data);
    }
    return p1;
}

// Min in BST
int findMin(node* p1){
    if(p1 == nullptr) return -1;
    node* temp = p1;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp->data;
}

// Max in BST
int findMax(node* p1){
    if(p1 == nullptr) return -1;
    node* temp = p1; 
    while(temp->right != nullptr){
        temp = temp->right; 
    }
    return temp->data; 
}

// Delete a node from BST
node* deleteFromBST(node* root,int data){

    if(root == nullptr) return root;

    if(root->data == data){

        // No child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // One child, left
        if(root->left != nullptr && root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // One child, right
        if(root->left == nullptr && root->right != nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Two children
        int mini = findMin(root->right);
        root->data = mini;
        root->right = deleteFromBST(root->right, mini);
        return root;
    }

    else if(data < root->data){
        root->left = deleteFromBST(root->left, data);
        return root;
    }

    else{
        root->right = deleteFromBST(root->right, data);
        return root;
    }
}

int main(){
    node* root = nullptr;

    root = binaryTree(root, 5);
    binaryTree(root, 1);
    binaryTree(root, 3);
    binaryTree(root, 7);
    binaryTree(root, 9);

    return 0;
}
