#include<bits/stdc++.h>
using namespace std; 

class Node{
    public: 
    int data; 
    Node* right; 
    Node* left; 

    Node(int data){
        this->data = data; 
        right = nullptr;
        left = nullptr; 
    }
};

class Solution {
public:
    int findPos(int in[], int x, int n) {
        for(int i = 0; i < n; i++) {
            if(in[i] == x) return i;
        }
        return -1;
    }

    Node* build(int in[], int post[], int &postIdx, int s, int e, int n) {
        if(postIdx < 0 || s > e) return nullptr;

        int val = post[postIdx--];
        Node* root = new Node(val);

        int pos = findPos(in, val, n);

        // Build right subtree first
        root->right = build(in, post, postIdx, pos + 1, e, n);
        root->left  = build(in, post, postIdx, s, pos - 1, n);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int postIdx = n - 1;

        return build(inorder.data(), postorder.data(), postIdx, 0, n - 1, n);
    }
};
