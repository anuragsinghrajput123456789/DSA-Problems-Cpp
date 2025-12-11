int findMaxInBst(node* root) {
    if (!root) return INT_MIN;
    while (root->right) root = root->right;
    return root->data;
}

// ✅ Find min in BST
int findMinInBst(node* root) {
    if (!root) return INT_MAX;
    while (root->left) root = root->left;
    return root->data;
}


int main(){




    
    return 0; 
}

