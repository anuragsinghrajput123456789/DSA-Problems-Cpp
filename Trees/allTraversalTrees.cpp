// ALL ORDER TRAVERSAL IN TREE'S

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inOrder(node* root){
    //base case
    if(root == nullptr){
        return ;
    }
    inOrder(root->left);
    cout << root->data << " "; // Added space for better readability
    inOrder(root->right);
}

void preOrder(node* root){
    //base case
    if(root == nullptr){
        return ;
    }
    cout << root->data << " "; // Added space for better readability
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    //base case
    if(root == nullptr){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " "; // Added space for better readability
}

vector<int> levelOrder(node* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }

    queue<node*> q; // Queue to store node pointers
    q.push(root); // Start with the root

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }
    return ans;
}

int main(){
    // Creating a valid binary tree structure
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(44);
    node* p5 = new node(55); // Adding more nodes for a more complex tree

    p1->left = p2;
    p1->right = p3;
    p2->left = p4; // p2's left child
    p3->right = p5; // p3's right child

    cout << "PreOrder Traversal: ";
    preOrder(p1);
    cout << endl;

    cout << "PostOrder Traversal (starting from p2): ";
    postOrder(p2); // p2 is the root of a subtree (22, 44)
    cout << endl;

    cout << "InOrder Traversal (starting from p3): ";
    inOrder(p3); // p3 is the root of a subtree (33, 55)
    cout << endl;

    cout << "LevelOrder Traversal (starting from p1): ";
    vector<int> levelOrderResult = levelOrder(p1);
    for(int data : levelOrderResult){
        cout << data << " ";
    }
    cout << endl;

    cout << "LevelOrder Traversal (starting from p4 - single node): ";
    vector<int> levelOrderSingleNode = levelOrder(p4);
    for(int data : levelOrderSingleNode){
        cout << data << " ";
    }
    cout << endl;

    // Don't forget to deallocate memory to prevent memory leaks
    // (For simplicity, not implemented here, but good practice for larger programs)
    // delete p1; delete p2; delete p3; delete p4; delete p5;

    return 0;
}