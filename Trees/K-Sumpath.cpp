#include<bits/stdc++.h>
using namespace std; 
class Node {
    int data; 
    Node* left; 
    Node* right; 
  public:
    
    void solve(Node* root,int k,int &count , vector<int>&path){
      //base case
      if(root == nullptr){
          return ; 
      }
      path.push_back(root->data);
      int n = path.size(); 
      
      //left ki call mardi bhai abb
      solve(root->left, k,count,path);
      
      //right ki call mardi bhai abbb
      solve(root->right, k,count,path);
     
     //check for k sum 
     int sum = 0; 
     for(int i=n-1; i>=0; i--){
         sum += path[i]; 
         if(sum == k)
             count++;
     }
     path.pop_back(); 
}
    
    int sumK(Node *root, int k) {
        // code here
        vector<int> path; 
        int count = 0 ;
        solve(root,k,count,path); 
        return count; 
    }
};

int main(){

    
    return 0; 
}