/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1; // Changed 'succes' to 'succ' for consistency

    TreeNode* temp = root;

    // Phase 1: Find the 'key' node and simultaneously track potential predecessor and successor
    // This loop finds the key node and sets 'pred' and 'succ' based on ancestors.
    while (temp != NULL) { // Added NULL check to prevent crash if key is not found
        if (temp->data == key) {
            break; // Found the key node, exit the loop
        }

        if (temp->data > key) {
            // Current node is greater than key, so it could be a successor
            succ = temp->data; // Update potential successor
            temp = temp->left; // Move left to find a smaller value or the key
        } else { // temp->data < key
            // Current node is smaller than key, so it could be a predecessor
            pred = temp->data; // Update potential predecessor
            temp = temp->right; // Move right to find a larger value or the key
        }
    }

    // After the loop, 'temp' points to the 'key' node if found, or NULL if not found.

    // If the key node was not found in the tree
    if (temp == NULL) {
        return {pred, succ}; // Returns initial -1, -1 or the last ancestor values
    }

    // Phase 2: Find the actual predecessor from the left subtree (if it exists)
    // The predecessor is the rightmost node in the left subtree of 'temp'.
    if (temp->left != NULL) {
        TreeNode* leftSubtree = temp->left;
        while (leftSubtree->right != NULL) {
            leftSubtree = leftSubtree->right;
        }
        pred = leftSubtree->data;
    }

    // Phase 3: Find the actual successor from the right subtree (if it exists)
    // The successor is the leftmost node in the right subtree of 'temp'.
    if (temp->right != NULL) {
        TreeNode* rightSubtree = temp->right;
        while (rightSubtree->left != NULL) {
            rightSubtree = rightSubtree->left;
        }
        succ = rightSubtree->data;
    }
    
    // Create and return the pair
    pair<int, int> ans(pred, succ);
    return ans;
}