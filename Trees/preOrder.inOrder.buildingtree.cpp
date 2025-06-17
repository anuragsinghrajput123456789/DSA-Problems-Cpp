#include <vector>
#include <map>

// This line allows you to use standard library components without the 'std::' prefix
using namespace std; 

// Definition of the Node class
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
    // To keep track of the current element in preorder traversal across recursive calls
    int preOrderIndex; 

    // Function to find the position of an element in the inorder array
    // This maintains your O(N) search for each element
    int findPost(vector<int>& in, int element, int n) { // 'vector' instead of 'std::vector'
        for (int i = 0; i < n; i++) {
            if (in[i] == element) {
                return i;
            }
        }
        return -1; // Should ideally always find the element
    }

    Node* solve(vector<int> &in, vector<int> &pre, int inorderStart, int inorderEnd, int n) { // 'vector' instead of 'std::vector'
        // Base case: If we've processed all preorder elements or the inorder range is invalid
        if (preOrderIndex >= n || inorderStart > inorderEnd) {
            return nullptr;
        }

        // The current element in preorder is always the root of the current subtree
        int element = pre[preOrderIndex++]; 
        Node* root = new Node(element); // Corrected to 'Node' (capital N)
        
        // Find the position of this root element in the inorder traversal
        int position = findPost(in, element, n); 

        // Recursive call for the left subtree
        // Its inorder range is from inorderStart to (position - 1)
        root->left = solve(in, pre, inorderStart, position - 1, n);
        
        // Recursive call for the right subtree
        // Its inorder range is from (position + 1) to inorderEnd
        root->right = solve(in, pre, position + 1, inorderEnd, n); 
        
        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) { // 'vector' instead of 'std::vector'
        preOrderIndex = 0; // Initialize the preorder index to start from the beginning
        int n = inorder.size(); // Get the size of the traversals

        // Start the recursive process to build the tree
        Node* ans = solve(inorder, preorder, 0, n - 1, n); 
        return ans;
    }
};


int main(){


return 0
}