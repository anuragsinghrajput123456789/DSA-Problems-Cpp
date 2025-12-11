#include<bits/stdc++.h>
using namespace std; 
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    int findPos(int in[], int x, int n) {
        for(int i=0; i<n; i++) {
            if(in[i] == x) return i;
        }
        return -1;
    }

    Node* build(int in[], int pre[], int &preIdx, int s, int e, int n) {
        if(preIdx >= n || s > e) return nullptr;

        int val = pre[preIdx++];
        Node* root = new Node(val);

        int pos = findPos(in, val, n);

        root->left = build(in, pre, preIdx, s, pos - 1, n);
        root->right = build(in, pre, preIdx, pos + 1, e, n);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = preorder.size();
        int preIdx = 0;
        return build(inorder.data(), preorder.data(), preIdx, 0, n - 1, n);
    }
};


int main(){



    
    return 0; 
}