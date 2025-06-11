/*
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
}; */
#include<bits/stdc++.h>
using namespace std; 
class Node{
    int data; 
    Node* left; 
    Node* right; 
public:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        // Base case: If root is null, we've gone past a leaf node
        if (root == nullptr) {
            return;
        }

        // Add current node's data to the sum
        sum += root->data;
        // Increment length for the current path
        len++;

        // If it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = std::max(sum, maxSum);
            }
            return; // Reached a leaf, no need to go further down this path
        }

        // Recur for left and right children
        solve(root->left, sum, maxSum, len, maxLen);
        solve(root->right, sum, maxSum, len, maxLen);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0; // Stores the maximum length found so far
        int maxSum = INT_MIN; // Stores the maximum sum for the longest path

        // Start the recursive traversal from the root
        // Initial sum is 0, initial length is 0. These will be updated for the root node inside solve.
        solve(root, 0, maxSum, 0, maxLen);

        return maxSum;
    }
};

int main(){

    return 0; 
}