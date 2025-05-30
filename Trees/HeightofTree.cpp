#include<bits/stdc++.h>
using namespace std;


class Node{
    int data; 
    Node* left; 
    Node* right; 
    
  public:
    int height(Node* node) {
        // code here
        //base case 
        if(node == NULL){
            return -1; 
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right) + 1;
        return ans; 
        
    }
};

int main(){


    return 0; 
}
