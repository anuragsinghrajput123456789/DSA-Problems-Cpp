#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* left;
  node* right;

  node(int data){
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

void inorderIter(node* root){
  stack<node*> st;
  node* curr = root;

  while(curr != nullptr || !st.empty()){
    while(curr != nullptr){
      st.push(curr);
      curr = curr->left;
    }

    curr = st.top();
    st.pop();
    cout << curr->data << " ";
    curr = curr->right;
  }
}

void preorderIter(node* root){
  if(root == nullptr) return;

  stack<node*> st;
  st.push(root);

  while(!st.empty()){
    node* temp = st.top();
    st.pop();
    cout << temp->data << " ";

    if(temp->right) st.push(temp->right);
    if(temp->left) st.push(temp->left);
  }
}

void postorderIter(node* root){
  if(root == nullptr) return;

  stack<node*> s1, s2;
  s1.push(root);

  while(!s1.empty()){
    node* temp = s1.top();
    s1.pop();
    s2.push(temp);

    if(temp->left) s1.push(temp->left);
    if(temp->right) s1.push(temp->right);
  }

  while(!s2.empty()){
    cout << s2.top()->data << " ";
    s2.pop();
  }
}

void levelOrder(node* root){
  if(root == nullptr) return;

  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    for(int i = 0; i < size; i++){
      node* temp = q.front();
      q.pop();
      cout << temp->data << " ";

      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
    cout << endl;
  }
}

node* buildFromLevel(node* p1){
  queue<node*>q;
  q.push(p1);
  cout << "Enter data for root " << endl;
}

void revereLevelOrder(node* root){
  if(root == nullptr)return ;
  stack<int>st; 
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    for(int i = 0; i < size; i++){
      node* temp = q.front();
      q.pop();
      st.push(temp->data);

      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
    cout << endl;
    
    
    while(!st.empty()){
      cout << st.top() << " "; 
      st.pop();
    }
  }
}


int main(){
  node* p1 = new node(1);
  node* p2 = new node(2);
  node* p3 = new node(3);
  node* p4 = new node(4);
  node* p5 = new node(5);
  node* p6 = new node(6);

  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;
  p3->left = p6;

  
}
