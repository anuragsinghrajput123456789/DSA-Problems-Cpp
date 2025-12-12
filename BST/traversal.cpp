#include<bits/stdc++.h>
using namespace std                                                ;

class node                                                         {
public: 
    int data; 
    node* left; 
    node* right                                                    ;

    node(int data)                                                 {
        this->data = data                                          ;
        left = nullptr                                             ;
        right = nullptr                                            ;}};

// Normal Traversals
void inOrder(node* p1)                                             {
    if(p1 == nullptr) return                                       ;
    inOrder(p1->left)                                              ;
    cout << p1->data << " "                                        ;
    inOrder(p1->right)                                             ;}

void preOrder(node* p1)                                            {
    if(p1 == nullptr) return                                       ;
    cout << p1->data << " "                                        ;
    preOrder(p1->left)                                             ;
    preOrder(p1->right)                                            ;}

void postOrder(node* p1)                                           {
    if(p1 == nullptr) return                                       ;
    postOrder(p1->left)                                            ;
    postOrder(p1->right)                                           ;
    cout << p1->data << " "                                        ;}

// Level Order
void levelOrder(node* p1)                                          {
    if(p1 == nullptr) return                                       ;

    queue<node*> q                                                 ;
    q.push(p1)                                                     ;

    while(!q.empty())                                              {
        node* temp = q.front()                                     ;
        q.pop()                                                    ;

        cout << temp->data << " "                                  ;

        if(temp->left != nullptr) q.push(temp->left)               ;
        if(temp->right != nullptr) q.push(temp->right)             ;}}

// Morris Inorder Traversal
void morrisInorder(node* root)                                     {
    node* curr = root                                              ;

    while(curr != nullptr)                                         {
        if(curr->left == nullptr)                                  {
            cout << curr->data << " "                              ;
            curr = curr->right                                     ;
        } 
        else                                                       {
            node* pred = curr->left                                ;
            while(pred->right != nullptr && pred->right != curr)   {
                pred = pred->right                                 ;}

            if(pred->right == nullptr)                             {
                pred->right = curr                                 ;
                curr = curr->left                                  ;
            } 
            else                                                   {
                pred->right = nullptr                              ;
                cout << curr->data << " "                          ;
                curr = curr->right                                 ;}}}}

// Morris Preorder Traversal
void morrisPreorder(node* root)                                    {
    node* curr = root                                              ;

    while(curr != nullptr)                                         {
        if(curr->left == nullptr)                                  {
            cout << curr->data << " "                              ;
            curr = curr->right                                     ;}
        else                                                       {
            node* pred = curr->left                                ;
            while(pred->right != nullptr && pred->right != curr)   {
                pred = pred->right                                 ;}

            if(pred->right == nullptr)                             {
                cout << curr->data << " "                          ;
                pred->right = curr                                 ;
                curr = curr->left                                  ;}
            else                                                   {
                pred->right = nullptr                              ;
                curr = curr->right                                 ;}}}}

// Insert into BST
node* binaryTree(node* p1, int data)                               {
    if(p1 == nullptr)                                              {
        return new node(data)                                      ;}

    if(data < p1->data)                                            {
        p1->left = binaryTree(p1->left, data)                      ;
    } 
    else                                                           {
        p1->right = binaryTree(p1->right, data)                    ;}

    return p1                                                      ;}

int findMin(node* p1)                                              {
  node* temp = p1                                                  ;
  while(temp->left != nullptr)                                     {
    temp = temp->left                                              ;}
  return temp->data                                                ;}

int findMax(node* p1)                                              {
  node* temp = p1; 
  while(temp->right != nullptr)                                    {
    temp = temp->right;                                            }
  return temp->data;                                               }

int main()                                                         {
    node* root = nullptr                                           ;

    // Build BST
    root = binaryTree(root, 5)                                     ;
    binaryTree(root, 1)                                            ;
    binaryTree(root, 3)                                            ;
    binaryTree(root, 7)                                            ;
    binaryTree(root, 9)                                            ;

    cout << findMax(root) << endl                                  ;
    cout << findMin(root) << endl                                  ;

    return 0                                                       ;}
