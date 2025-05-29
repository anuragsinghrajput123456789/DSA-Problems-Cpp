#include <iostream> // For cout, endl
#include <queue>    // For std::queue

// Using namespace std for brevity in this example, as in your original code.
// In larger projects, it's often better to use std::cout, std::queue, etc.
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inOrder(node* head) {
    // Base case
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->data << " "; // Changed endl to " " for better single-line output per traversal
    inOrder(head->right);
}

void preOrder(node* head) {
    // Base case
    if (head == nullptr) {
        return;
    }
    cout << head->data << " "; // Changed endl to " "
    preOrder(head->left);
    preOrder(head->right);
}

void levelOrder(node* head) {
    // Base case: if the tree is empty
    if (head == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<node*> q;
    q.push(head);
    q.push(nullptr); // Nullptr acts as a delimiter for levels

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == nullptr) { // Current level has been completely processed
            cout << endl;      // Move to the next line for the new level
            if (!q.empty()) {  // If there are more nodes for subsequent levels
                q.push(nullptr); // Add delimiter for the next level
            }
        } else {
            // Process the current node
            cout << temp->data << " "; // Print node's data

            // Enqueue left child if it exists
            if (temp->left) {
                q.push(temp->left);
            }

            // Enqueue right child if it exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Function to delete the tree and free memory
void deleteTree(node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    deleteTree(currentNode->left);
    deleteTree(currentNode->right);
    // cout << "Deleting node: " << currentNode->data << endl; // Optional for debugging
    delete currentNode;
}

int main() {
    // Manually creating nodes
    node* head = new node(11);
    node* p1 = new node(22);
    node* p2 = new node(33);
    node* p3 = new node(4);
    node* p4 = new node(5);
    node* p5 = new node(6);
    node* p6 = new node(17);
    node* p7 = new node(88); // This node is created but not attached to the main tree

    // Linking nodes to form the tree structure:
    //        11 (head)
    //       /  \
    //   22(p1)  33(p2)
    //   / \     / \
    // 4(p3) 5(p4) 6(p5) 17(p6)

    head->left = p1;
    head->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    cout << "In-Order Traversal:" << endl;
    inOrder(head);
    cout << endl << endl; // Extra endl for spacing between traversals

    cout << "Pre-Order Traversal:" << endl;
    preOrder(head);
    cout << endl << endl; // Extra endl for spacing

    cout << "Level-Order Traversal:" << endl;
    levelOrder(head);
    // The levelOrder function already prints newlines appropriately
    cout << endl; // Final newline after level order

    // --- Memory Cleanup ---
    cout << "Deleting the main tree..." << endl;
    deleteTree(head);
    head = nullptr;

    cout << "Deleting unattached node p7..." << endl;
    delete p7;
    p7 = nullptr;

    return 0;
}
