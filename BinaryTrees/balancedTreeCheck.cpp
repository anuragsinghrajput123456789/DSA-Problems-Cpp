#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  // Constructor to initialize a new node
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
private:
  int height(Node *root)
  {
    if (root == nullptr)
      return 0;
    return max(height(root->left), height(root->right)) + 1;
  }

public:
  bool isBalanced(Node *root)
  {
    // code here
    if (root == nullptr)
      return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && diff)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main(){


  
  return 0;
}