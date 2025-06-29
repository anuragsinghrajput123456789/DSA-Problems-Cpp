#include <iostream> // For std::cout, std::endl
#include <vector>   // For std::vector
#include <algorithm> // For std::min, std::max (if used for general tree min/max)
#include <limits>    // For std::numeric_limits<int>::max() and min()

// It's generally better to include specific headers rather than <bits/stdc++.h>
// for clarity and portability.

// You can use `using namespace std;` if you prefer for competitive programming or small scripts,
// but for larger projects, it's often advised to qualify names with `std::`.
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // IMPORTANT: Add a destructor to prevent memory leaks.
    // This will recursively delete the left and right subtrees.
    ~node() {
        delete left;
        delete right;
    }
};

// --- FIX: Corrected inOrder to collect nodes into a vector by reference ---
// This function takes a reference to the vector 'ans' to accumulate results.
void getInOrderTraversal(node* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    getInOrderTraversal(root->left, ans);
    ans.push_back(root->data);
    getInOrderTraversal(root->right, ans);
}

// This function directly prints the in-order traversal (your original inOrderprint).
// No change needed here if its purpose is just to print.
void inOrderPrint(node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << endl;
    inOrderPrint(root->right);
}


// --- FIX: Corrected noOfnode base case ---
int noOfnode(node* root){
    if (root == nullptr) {
        return 0; // Correct: An empty tree has 0 nodes
    }
    int r = noOfnode(root->right);
    int l = noOfnode(root->left);
    int total_nodes = r + l + 1; // +1 for the current node
    return total_nodes;
}

// --- FIX: Min/Max for General Binary Tree ---
// These functions are now modified to find the minimum/maximum in a
// general binary tree (by checking all nodes), not just assuming a BST.
// If you truly need the BST-specific min/max (leftmost/rightmost), rename them
// and ensure the tree IS a BST.
int findMinInGeneralTree(node* root) {
    if (root == nullptr) {
        return numeric_limits<int>::max(); // Return a very large value if tree is empty
    }
    int res = root->data;
    int left_min = findMinInGeneralTree(root->left);
    int right_min = findMinInGeneralTree(root->right);
    res = min(res, left_min);
    res = min(res, right_min);
    return res;
}

int findMaxInGeneralTree(node* root) {
    if (root == nullptr) {
        return numeric_limits<int>::min(); // Return a very small value if tree is empty
    }
    int res = root->data;
    int left_max = findMaxInGeneralTree(root->left);
    int right_max = findMaxInGeneralTree(root->right);
    res = max(res, left_max);
    res = max(res, right_max);
    return res;
}

int main(){

    // Constructing the binary tree
    // This is a general binary tree, not strictly a BST by value property.
    //          44
    //         /  \
    //        22   66
    //       /  \ /
    //      11  33 55
    // In-order traversal: 11, 22, 33, 44, 55, 66

    node* p1 = new node(44);
    node* p2 = new node(22);
    node* p3 = new node(66);
    node* p4 = new node(11);
    node* p5 = new node(33);
    node* p6 = new node(55);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6; // 66's left child is 55.

    // --- Demonstrate corrected inOrder traversal ---
    vector<int> ans_collected; // This vector will be correctly populated
    getInOrderTraversal(p1, ans_collected); // Call the fixed function

    cout << "--- In-order Traversal (Collected in Vector) ---" << endl;
    int n = ans_collected.size(); // Use size() of the correctly populated vector
    for(int i = 0; i < n; i++){
        cout << ans_collected[i] << endl;
    }
    cout << "------------------------------------------" << endl;

    // --- Demonstrate original inOrderPrint ---
    cout << "--- In-order Traversal (Direct Print) ---" << endl;
    inOrderPrint(p1);
    cout << "------------------------------------------" << endl;

    // --- Demonstrate corrected noOfnode ---
    cout << "Number of nodes in the tree: " << noOfnode(p1) << endl;
    cout << "------------------------------------------" << endl;

    // --- Demonstrate general tree min/max ---
    cout << "Minimum value in the tree: " << findMinInGeneralTree(p1) << endl;
    cout << "Maximum value in the tree: " << findMaxInGeneralTree(p1) << endl;
    cout << "------------------------------------------" << endl;

    // --- Memory Deallocation ---
    // Delete the root node. Due to the destructor in 'node' class,
    // this will recursively deallocate all nodes in the tree.
    delete p1;

    return 0;
}