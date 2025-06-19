//ALL TRAVERSAL OF THE TREE'S ARE THERE ....


#include <iostream> // For input/output operations (cout)
#include <vector>   // For std::vector in levelOrder
#include <queue>    // For std::queue in levelOrder
#include <map> // Although not directly used in this snippet, it was in the previous request.

// Using standard namespace to avoid std:: prefix
using namespace std;

// Node class definition for the binary tree
class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a new node
    node(int data) {
        this->data = data;
        this->left = nullptr; // Initialize left child to null
        this->right = nullptr; // Initialize right child to null
    }
};

// In-order traversal: Left -> Root -> Right
void inOrder(node* root) {
    // Base case: if the current node is null, return
    if (root == nullptr) {
        return;
    }

    // Recursively traverse the left subtree
    inOrder(root->left);
    // Print the data of the current node
    cout << root->data << " ";
    // Recursively traverse the right subtree
    inOrder(root->right);
}

// Pre-order traversal: Root -> Left -> Right
void preOrder(node* root) {
    // Base case: if the current node is null, return
    if (root == nullptr) {
        return;
    }

    // Print the data of the current node
    cout << root->data << " ";
    // Recursively traverse the left subtree
    preOrder(root->left);
    // Recursively traverse the right subtree
    preOrder(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postOrder(node* root) {
    // Base case: if the current node is null, return
    if (root == nullptr) {
        return;
    }

    // Recursively traverse the left subtree
    postOrder(root->left);
    // Recursively traverse the right subtree
    postOrder(root->right);
    // Print the data of the current node
    cout << root->data << " ";
}

// Level-order traversal: Breadth-First Search (BFS)
vector<int> levelOrder(node* root) {
    // Base case: if the root is null, return an empty vector
    if (root == nullptr) {
        return {}; // Correctly returns an empty vector
    }

    queue<node*> q; // Use queue for BFS, type corrected to 'node*'
    q.push(root);   // Push the root node to start traversal
    vector<int> ans; // Vector to store the level order traversal result

    while (!q.empty()) {
        node* current = q.front(); // Get the node at the front of the queue
        q.pop();                   // Remove the front node from the queue

        ans.push_back(current->data); // Add the data of the current node to the result vector

        // If the left child exists, push it to the queue
        if (current->left) {
            q.push(current->left);
        }

        // If the right child exists, push it to the queue
        if (current->right) {
            q.push(current->right);
        }
    }
    return ans; // Return the complete level order traversal vector
}

int main() {
    // Creating nodes for a sample binary tree
    //       11
    //      /  \
    //    22    33
    //   /  \
    // 44    55
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(55);
    node* p4 = new node(33);
    node* p5 = new node(44);

    // Establishing connections (tree structure)
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    cout << "In-order Traversal: ";
    inOrder(p1);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(p1);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(p1);
    cout << endl;

    cout << "Level-order Traversal: ";
    vector<int> levelOrderResult = levelOrder(p1);
    for (int data : levelOrderResult) {
        cout << data << " ";
    }
    cout << endl;

    // Remember to free dynamically allocated memory to prevent memory leaks
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}
