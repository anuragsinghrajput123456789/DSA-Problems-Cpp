///BST TRAVERSAL AND FINDING THE MIN AND MAX IN THE BST

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

// ✅ Validate BST using inorder traversal
bool isBstUtil(node* root, node* &prev) {
    if (!root) return true;

    if (!isBstUtil(root->left, prev)) return false;

    if (prev != nullptr && root->data <= prev->data) return false;
    prev = root;

    return isBstUtil(root->right, prev);
}

bool isBst(node* root) {
    node* prev = nullptr;
    return isBstUtil(root, prev);
}

// ✅ Find max in BST
int findMaxInBst(node* root) {
    if (!root) return INT_MIN;
    while (root->right) root = root->right;
    return root->data;
}

// ✅ Find min in BST
int findMinInBst(node* root) {
    if (!root) return INT_MAX;
    while (root->left) root = root->left;
    return root->data;
}

// ✅ Search in BST
bool findInBst(node* root, int data) {
    if (!root) return false;
    if (root->data == data) return true;
    return data < root->data ? findInBst(root->left, data) : findInBst(root->right, data);
}

// ✅ InOrder Traversal
void inOrder(node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// ✅ PreOrder Traversal
void preOrder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// ✅ PostOrder Traversal
void postOrder(node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// ✅ Optional: Insert in BST
node* insert(node* root, int data) {
    if (!root) return new node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// ✅ Optional: Level-order traversal
void levelOrder(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}



node* deleteFromBst(node* root,int data){
  //base case
  if(root == nullptr) return root;
  
  if(root->data == data){
    //0 child
    if(root->left == nullptr && root->right == nullptr){
      delete root; 
      return nullptr;
    }
    
    //1 child
    if(root->left != nullptr && root->right == nullptr){
      node* temp = root->left; 
      delete root; 
      return temp; 
    }
    
    
    if(root->left == nullptr && root->right != nullptr){
      node* temp = root->right; 
      delete root; 
      return temp; 
    }
    //2 child
    if(root->left != nullptr && root->right != nullptr){
      int mini = findMinInBst(root->right);
      root->data = mini;
      root->right = deleteFromBst(root->right, mini);
    }
  }
  
  else if(root->data > data){
    root->left = deleteFromBst(root->left, data);
    return root; 
  }
  
  else{
    //right part me jaoo bhai..
    root->right = deleteFromBst(root->right,data);
    return root; 
  }
}


// ✅ Main Function to test everything
int main() {
    // Build a simple BST
    node* root = nullptr;
    vector<int> values = {10, 5, 15, 2, 8, 12, 20};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << "\nPreOrder Traversal: ";
    preOrder(root);
    cout << "\nPostOrder Traversal: ";
    postOrder(root);
    cout << "\nLevelOrder Traversal: ";
    levelOrder(root);

    cout << "\n\nBST Valid: " << (isBst(root) ? "Yes" : "No");
    cout << "\nMinimum in BST: " << findMinInBst(root);
    cout << "\nMaximum in BST: " << findMaxInBst(root);
    cout << "\nFind 8 in BST: " << (findInBst(root, 8) ? "Found" : "Not Found");
    cout << "\nFind 100 in BST: " << (findInBst(root, 100) ? "Found" : "Not Found");

    return 0;
}
