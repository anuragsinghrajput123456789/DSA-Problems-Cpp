#include<iostream> // Use iostream for input/output
#include<bits/stdc++.h> // A common competitive programming header, but often better to include specific headers

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a new node
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a new node into a BST
// Returns the root of the modified BST
node* insertIntoBst(node* root, int data) {
    // Base case: If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return new node(data);
    }

    // If data is less than the current node's data, go to the left subtree
    if (data < root->data) {
        root->left = insertIntoBst(root->left, data);
    }
    // If data is greater than or equal to the current node's data, go to the right subtree
    else {
        root->right = insertIntoBst(root->right, data);
    }
    // Return the (potentially modified) root
    return root;
}

// Function to perform in-order traversal of the BST
// Prints elements in ascending order for a BST
void inOrder(node* root) {
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }
    // Recursively traverse the left subtree
    inOrder(root->left);
    // Print the data of the current node
    cout << root->data << " "; // Added space for better readability
    // Recursively traverse the right subtree
    inOrder(root->right);
}

// Function to find the maximum value in a BST
// The maximum value is the rightmost node
int maxInBst(node* root) {
    // If the tree is empty, return -1 (or throw an exception, depending on requirements)
    if (root == nullptr) {
        return -1;
    }

    node* temp = root;
    // Traverse to the rightmost node
    while (temp->right != nullptr) { // Corrected condition: continue as long as there's a right child
        temp = temp->right;
    }
    // Return the data of the rightmost node
    return temp->data;
}

// Function to find the minimum value in a BST
// The minimum value is the leftmost node
int minInBst(node* root) {
    // If the tree is empty, return -1
    if (root == nullptr) {
        return -1;
    }

    node* temp = root;
    // Traverse to the leftmost node
    while (temp->left != nullptr) { // Corrected condition: continue as long as there's a left child
        temp = temp->left;
    }
    // Return the data of the leftmost node
    return temp->data;
}

// Function to delete a node with a given data from a BST
// Returns the root of the modified BST
node* deleteFromBst(node* root, int data) {
    // Base case 1: If the tree is empty, the node is not found, so return NULL
    if (root == nullptr) {
        return nullptr; // Changed from 'return root;' to 'return nullptr;' for clarity
    }

    // Case 1: The node to be deleted is found
    if (root->data == data) {
        // Case 1.1: Node has 0 children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;      // Deallocate memory
            return nullptr;   // Return NULL as this subtree is now empty
        }
        // Case 1.2: Node has 1 child (left child)
        else if (root->left != nullptr && root->right == nullptr) {
            node* temp = root->left; // Store the left child
            delete root;             // Deallocate the current node
            return temp;             // Return the left child to replace the deleted node
        }
        // Case 1.3: Node has 1 child (right child)
        else if (root->left == nullptr && root->right != nullptr) {
            node* temp = root->right; // Store the right child
            delete root;              // Deallocate the current node
            return temp;              // Return the right child to replace the deleted node
        }
        // Case 1.4: Node has 2 children
        else { // (root->left != nullptr && root->right != nullptr)
            // Find the in-order successor (minimum value in the right subtree)
            int mini = minInBst(root->right);
            // Replace the current node's data with the in-order successor's data
            root->data = mini;
            // Recursively delete the in-order successor from the right subtree
            root->right = deleteFromBst(root->right, mini);
            // Return the current root (its data is now updated, and the successor is deleted)
            return root;
        }
    }
    // Case 2: Data to be deleted is less than current node's data, go left
    else if (root->data > data) {
        root->left = deleteFromBst(root->left, data); // Update the left child pointer
        return root;
    }
    // Case 3: Data to be deleted is greater than current node's data, go right
    else { // root->data < data
        root->right = deleteFromBst(root->right, data); // Update the right child pointer
        return root;
    }
}

// Main function to demonstrate BST operations
int main() {
    node* root = NULL; // Initialize an empty BST

    // Build a BST by inserting elements
    // Example: 50, 30, 70, 20, 40, 60, 80
    root = insertIntoBst(root, 50);
    root = insertIntoBst(root, 30);
    root = insertIntoBst(root, 70);
    root = insertIntoBst(root, 20);
    root = insertIntoBst(root, 40);
    root = insertIntoBst(root, 60);
    root = insertIntoBst(root, 80);

    cout << "BST In-order traversal (initial): ";
    inOrder(root); // Expected: 20 30 40 50 60 70 80
    cout << endl;

    cout << "Minimum in BST: " << minInBst(root) << endl; // Expected: 20
    cout << "Maximum in BST: " << maxInBst(root) << endl; // Expected: 80

    // --- Deletion Examples ---

    // Example 1: Delete a leaf node (e.g., 20)
    cout << "\nDeleting 20 (leaf node)..." << endl;
    root = deleteFromBst(root, 20);
    cout << "BST In-order traversal after deleting 20: ";
    inOrder(root); // Expected: 30 40 50 60 70 80
    cout << endl;

    // Example 2: Delete a node with one child (e.g., 70, which has 80 as right child)
    cout << "\nDeleting 70 (node with one child)..." << endl;
    root = deleteFromBst(root, 70);
    cout << "BST In-order traversal after deleting 70: ";
    inOrder(root); // Expected: 30 40 50 60 80
    cout << endl;

    // Example 3: Delete a node with two children (e.g., 50 - the root)
    cout << "\nDeleting 50 (node with two children - root)..." << endl;
    root = deleteFromBst(root, 50);
    cout << "BST In-order traversal after deleting 50: ";
    inOrder(root); // Expected: 30 40 60 80 (50 replaced by 60, then 60 deleted from right subtree)
    cout << endl;

    // Example 4: Delete a node that doesn't exist (e.g., 99)
    cout << "\nAttempting to delete 99 (does not exist)..." << endl;
    root = deleteFromBst(root, 99);
    cout << "BST In-order traversal after trying to delete 99: ";
    inOrder(root); // Should remain unchanged
    cout << endl;

    // Example 5: Delete 30 (node with one child)
    cout << "\nDeleting 30 (node with one child)..." << endl;
    root = deleteFromBst(root, 30);
    cout << "BST In-order traversal after deleting 30: ";
    inOrder(root); // Expected: 40 60 80
    cout << endl;
    
    // Example 6: Delete 60 (node with one child)
    cout << "\nDeleting 60 (leaf node)..." << endl;
    root = deleteFromBst(root, 60);
    cout << "BST In-order traversal after deleting 60: ";
    inOrder(root); // Expected: 40 80
    cout << endl;

    return 0;
}