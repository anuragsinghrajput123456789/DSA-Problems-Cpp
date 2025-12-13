#include <bits/stdc++.h>
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

void inOrder(node* root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == nullptr) return;
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
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

node* insertIntoBST(node* root, int data){
    if(root == nullptr){
        return new node(data);
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

node* takeInput(){
    int data;
    node* root = nullptr;

    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

int max(node* p1){
  if(p1 == nullptr)return -1;
  node* temp = p1; 
  while(temp->left != nullptr){
    temp = temp->left;
  }
  return temp->data << endl; 
}

int min(node* p1){
  if(p1 == nullptr)return -1;
  node* temp = p1; 
  while(temp->right){
    temp = temp->right;
  }
  return temp->data << endl;
}


int main(){

    // BST Example 1
    node* root1 = nullptr;
    int arr1[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    
    for(auto x : arr1){
      root1 = insertIntoBST(root1,x);
    }

    cout << "Level Order BST 1" << endl;
    levelOrder(root1);

    cout << "Inorder BST 1" << endl;
    inOrder(root1);
    
    cout << "PreOrder BST 1 " << endl;
    preOrder(root1);
    
    cout << "PostOrder BST 1 " << endl;
    postOrder(root1);
    
    cout << max(root1) << endl;
    cout << min(root1) << endl; 
    
    

    return 0;
}
