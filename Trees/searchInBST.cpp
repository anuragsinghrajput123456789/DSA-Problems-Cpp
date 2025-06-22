/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == nullptr){
         return false; 
    }

    if(root->data == x){
      return true;
    }

    if(root->data < x){
     //right wale part me dhondo bhai
     return searchInBST(root->right,x); 
    }
    else{
      return searchInBST(root->left,x); 
    }
}

int main(){


    return 0; 
}