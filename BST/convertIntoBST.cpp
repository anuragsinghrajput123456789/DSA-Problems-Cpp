#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void convertIntoBst(TreeNode<int>*root,TreeNode<int>* &head){
   //base case
   if(root == nullptr)return ; 

  //step 1 :- recursion karlega pehell right part karke aoo
   convertIntoBst(root->right,head);
  
   root->right = head;
 
   if(head != nullptr)head->left = root;  

   head = root; 

   convertIntoBst(root->left , head);
}

int main(){


    return 0; 
}