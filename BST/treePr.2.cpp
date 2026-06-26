
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//---------------- Level Order Traversal ----------------//

void levelOrder(node* root){

    if(root == nullptr)
        return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    cout << endl;
}

//---------------- ZigZag Traversal ----------------//

vector<int> zigZag(node* root){

    vector<int> ans;

    if(root == nullptr)
        return ans;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();

        vector<int> level(size);

        for(int i = 0; i < size; i++){

            node* temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;

            level[index] = temp->data;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        for(int x : level)
            ans.push_back(x);

        leftToRight = !leftToRight;
    }

    return ans;
}

//---------------- Left Boundary ----------------//

void traversalLeft(node* root, vector<int> &ans){

    if(root == nullptr ||
      (root->left == nullptr && root->right == nullptr))
        return;

    ans.push_back(root->data);

    if(root->left)
        traversalLeft(root->left, ans);
    else
        traversalLeft(root->right, ans);
}

//---------------- Leaf Nodes ----------------//

void printLeafNode(node* root, vector<int> &ans){

    if(root == nullptr)
        return;

    if(root->left == nullptr && root->right == nullptr){

        ans.push_back(root->data);
        return;
    }

    printLeafNode(root->left, ans);
    printLeafNode(root->right, ans);
}

//---------------- Right Boundary ----------------//

void traverseRight(node* root, vector<int> &ans){

    if(root == nullptr ||
      (root->left == nullptr && root->right == nullptr))
        return;

    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // Store while coming back
    ans.push_back(root->data);
}

//---------------- Boundary Traversal ----------------//

vector<int> boundaryTraversal(node* root){

    vector<int> ans;

    if(root == nullptr)
        return ans;

    // Root node
    ans.push_back(root->data);

    // Left Boundary
    traversalLeft(root->left, ans);

    // Leaf Nodes
    printLeafNode(root->left, ans);
    printLeafNode(root->right, ans);

    // Right Boundary
    traverseRight(root->right, ans);

    return ans;
}

//---------------- Main ----------------//

int main(){

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    // Level Order
    cout << "Level Order : ";
    levelOrder(root);

    // ZigZag Traversal
    vector<int> zig = zigZag(root);

    cout << "ZigZag Traversal : ";

    for(int x : zig)
        cout << x << " ";

    cout << endl;

    // Boundary Traversal
    vector<int> boundary = boundaryTraversal(root);

    cout << "Boundary Traversal : ";

    for(int x : boundary)
        cout << x << " ";

    cout << endl;

    return 0;
}