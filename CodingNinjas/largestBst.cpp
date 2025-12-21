#include<bits/stdc++.h>
#include <climits>
using namespace std;

class info{
public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

class TreeNode{
    public: 
    int data; 
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data; 
        left = NULL; 
        right = NULL; 
    }
};

info solve(TreeNode* root, int &ans){
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left  = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;
    curr.size = left.size + right.size + 1;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);

    if(left.isBst && right.isBst &&
       root->data > left.maxi &&
       root->data < right.mini){
        curr.isBst = true;
        ans = max(ans, curr.size);
    } else {
        curr.isBst = false;
    }

    return curr;
}

int largestBST(TreeNode* root){
    int ans = 0;
    solve(root, ans);
    return ans;
}


int main(){



    return 0; 
}