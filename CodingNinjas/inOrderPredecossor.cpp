#include <iostream>
#include<bits/stdc++.h>
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

void inOrderTraversal(node* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, ans);
    ans.push_back(root->data);
    inOrderTraversal(root->right, ans);
}

void inOrdert(node* root){
  //base case
  if(root == NULL){
    return ;
  }
  
  inOrdert(root->left);
  cout << root->data << endl; 
  inOrdert(root->right);
}

int main() {
    node* p1 = new node(44);
    node* p2 = new node(22);
    node* p3 = new node(55);
    node* p4 = new node(11);
    node* p5 = new node(33);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    vector<int> inorderElements;
    inOrderTraversal(p1, inorderElements);

    int key = 33;
    pair<int, int> result = {-1, -1};

    for (size_t i = 0; i < inorderElements.size(); ++i) {
        if (inorderElements[i] == key) {
            if (i > 0) {
                result.first = inorderElements[i - 1];
            }
            if (i < inorderElements.size() - 1) {
                result.second = inorderElements[i + 1];
            }
            break;
        }
    }

    cout << "For key " << key << ":" << endl;
    cout << "Inorder Predecessor: " << (result.first != -1 ? to_string(result.first) : "N/A") << endl;
    cout << "Inorder Successor: " << (result.second != -1 ? to_string(result.second) : "N/A") << endl;

   inOrdert(p1);


    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}