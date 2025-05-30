#include<bits/stdc++.h> // Includes common C++ libraries
using namespace std;    // Uses the standard namespace

// Definition for a binary tree node
class node {
public:
    int data;     // Data stored in the node
    node* left;   // Pointer to the left child
    node* right;  // Pointer to the right child

    // Constructor to initialize a new node
    node(int data) {
        this->data = data;
        this->left = nullptr;  // Initialize left child to null
        this->right = nullptr; // Initialize right child to null
    }
};

// Function to calculate the diameter and height of a binary tree efficiently (O(N) time complexity)
// It returns a pair: {diameter, height}
pair<int, int> diameterFast(node* head) {
    // Base case: if the node is null, diameter and height are both 0
    if (head == nullptr) {
        pair<int, int> p = make_pair(0, 0); // {diameter, height}
        return p;
    }

    // Recursively get diameter and height for left and right subtrees
    pair<int, int> leftAns = diameterFast(head->left);  // {left_diameter, left_height}
    pair<int, int> rightAns = diameterFast(head->right); // {right_diameter, right_height}

    // Calculate the diameter passing through the current node
    // This is the sum of heights of left and right subtrees + 1 (for the current node)
    int diameterThroughRoot = leftAns.second + rightAns.second + 1;

    // The overall diameter for the current subtree is the maximum of:
    // 1. Diameter of the left subtree (leftAns.first)
    // 2. Diameter of the right subtree (rightAns.first)
    // 3. Diameter passing through the current root (diameterThroughRoot)
    int currentDiameter = max({leftAns.first, rightAns.first, diameterThroughRoot});

    // The height of the current subtree is the maximum of the heights of its children + 1 (for the current node)
    int currentHeight = max(leftAns.second, rightAns.second) + 1;

    // Return the calculated diameter and height for the current subtree
    pair<int, int> ans = make_pair(currentDiameter, currentHeight);
    return ans;
}

// Function for Pre-order traversal (Root -> Left -> Right)
void preOrder(node* head) {
    // Base case: if the node is null, return
    if (head == nullptr) {
        return;
    }
    // Print the data of the current node
    cout << head->data << " ";
    // Recursively call for the left subtree
    preOrder(head->left);
    // Recursively call for the right subtree
    preOrder(head->right);
}

int main() {
    // Creating nodes for a simple binary tree
    //       11
    //      /  \
    //     22  33
    node* first = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);

    // Connecting the nodes to form the tree structure
    first->left = p2;
    first->right = p3;
    p2->left = nullptr;  // 22 has no left child
    p2->right = nullptr; // 22 has no right child
    // p3's children are already nullptr by default constructor, but can be explicitly set if needed:
    // p3->left = nullptr;
    // p3->right = nullptr;

    cout << "Pre-order traversal: ";
    preOrder(first); // Perform pre-order traversal starting from 'first' node
    cout << endl; // New line after traversal

    // Calculate and print the diameter of the tree
    pair<int, int> result = diameterFast(first);
    cout << "Diameter of the tree: " << result.first << endl;
    cout << "Height of the tree: " << result.second << endl;

    // Clean up dynamically allocated memory to prevent memory leaks
    delete first;
    delete p2;
    delete p3;

    return 0;
}
