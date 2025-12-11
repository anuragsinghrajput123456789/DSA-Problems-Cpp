#include<bits/stdc++.h>
using namespace std; 

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    pair<int,int> solve(Node* root){
        //base case 
        if(root == nullptr){
            pair<int,int> p = make_pair(0,0);
            return p; 
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int>res;
        
        //maxium sum incliing root node hai isme bhai...
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first,right.second);
        return res; 
    }
    
    int getMaxSum(Node *root) {
        // code here
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};

int main(){


    return 0; 
}