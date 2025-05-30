#include<bits/stdc++.h>
using namespace std; 


class Node{
  public:
  int data ;
  Node* right; 
  Node* left; 
    int rec(Node* root,int &diameter){
        if(!root) return 0;
        
        int lh = rec(root->left,diameter);
        int rh = rec(root->right,diameter);
        
        diameter = max(diameter,lh+rh);
        
        return 1 + max(lh,rh);
    }
    int diameter(Node* root) {
        int ans=0;
        rec(root,ans);
        return ans;
    }
};

int main(){

    return  0; 
}