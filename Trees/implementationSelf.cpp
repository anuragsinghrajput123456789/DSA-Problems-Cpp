// ALL ORDER TRAVERSAL IN TREE'S

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inOrder(node* root){
    //base case
    if(root == nullptr){
        return ;
    }
    inOrder(root->left);
    cout << root->data << " "; // Added space for better readability
    inOrder(root->right);
}

void preOrder(node* root){
    //base case
    if(root == nullptr){
        return ;
    }
    cout << root->data << " "; // Added space for better readability
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
  //base case
  if(root == nullptr){
    return ; 
  }
  postOrder(root->left);
  cout << root->data << endl;
  postOrder(root->right);
}

bool isBst(node* root){
  //base case
  node* prev = nullptr; 
  if(root != nullptr){
      if(!isBst(root->left)){
        return 0; 
      }
      if(prev!= nullptr && root->data <= prev->data){
        return 0; 
      }
      
      //prevrios ko data ko assign kar rahe pichla waha root
      
      prev = root;
      return isBst(root->right);
  }
  else{
    return 1; 
  }
}

bool isBstSelf(node* root){
  //base case
  if(root == nullptr){
    return 1; 
  }
  if(!isBstSelf(root->left)){
    return 0; 
  }
  node* prev = nullptr; 
  if(prev != nullptr && prev->data <= root->data){
    return 0;     
  }
  prev = root; 
  isBstSelf(root->right);
  return 1; 
}


vector<int> levelOrder(node* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }

    queue<node*> q; // Queue to store node pointers
    q.push(root); // Start with the root

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }
    return ans;
}


int main(){
    
    node* p = new node(5);
    node* p1 = new node(3);
    node* p2 = new node(6);
    node* p3 = new node(1);
    node* p4 = new node(4);
    
    
    p->left = p1; 
    p->right = p2; 
    p1->left = p3; 
    p1->right = p4;
    
    
    inOrder(p);
    cout << endl; 
    cout << isBstSelf(p);
    
    
    
    
    return 0;
}