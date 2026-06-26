#include<bits/stdc++.h>
using namespace std; 
class node{
    public: 
      int data; 
      node* right; 
      node* left; 

      node(int data){
          this->data = data; 
          this->left = nullptr; 
          this->right = nullptr; 
      }
};

void levelOrder(node* &root){
   if(root == nullptr)return ;

   queue<node*> q;
   q.push(root);
   
   while(!q.empty()){
      node* temp = q.front();
      q.pop();
      cout << temp->data << " ";

      if(temp->left != nullptr)q.push(temp->left);

      if(temp->right != nullptr)q.push(temp->right);

   }
}

pair<bool,int> isSumTree(node* &root){
    if(root == nullptr)return {true,0};
   
   if(root->left && root->right)return {true , root->data};
   
   pair<bool, int>left = isSumTree(root->left);
   pair<bool,int>right = isSumTree(root->right);

   bool left = left.first; 
   bool right = right.first; 

   bool condition  = root->data == left.second + right.second;

   pair<bool,int> ans; 
   
   if(left && right && condition){
     ans.first  = true;
     ans.second = 2*root->data;
   }
   else{
     ans.first = false; 
     ans.second = 0;
   }
   return ans; 
}

vector<int> zigZagTraversal(node* &root){
    vector<int> result;
    
    if(root == nullptr)return result;
    
    queue<node*> q;
    q.push(root);
    bool leftToright = true; 

    while(!q.empty()){
        
        /*process every level to check if it 
        is push in leftToright or rightToleft
        */

        int size = q.size();
        vector<int> ans; 

        for(int i=0; i<size; i++){
           node* frontNode = q.front();
           q.pop();
           
           int index = leftToright ? i : size - i - 1;
           ans[index] = frontNode->data; 
           
           if(frontNode->left != nullptr)q.push(frontNode->left);

           if(frontNode->right != nullptr)q.push(frontNode->right);
        }

        for(auto i : ans){
            result.push_back(ans);
        }
    }
    return result;
}


int main(){
  
  node* p1 = new node(11);
  node* p2 = new node(22);
  node* p3 = new node(33);
  node* p4 = new node(44);
  node* p5 = new node(55);

  p1->left = p2; 
  p1->right = p3; 
  p2->left = p4; 
  p2->right = p5; 

  levelOrder(p1);
   




    return 0; 
}
