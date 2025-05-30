#include <bits/stdc++.h>
using namespace std;
class Node
{

    Node* left; 
    Node* right; 
    int data;
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        // base case
        if (r1 == nullptr && r2 == nullptr)
        {
            return true;
        }
        if (r1 == nullptr && r2 != nullptr)
        {
            return false;
        }

        if (r1 != nullptr && r2 == nullptr)
        {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool value = r1->data == r2->data;

        if (left && right && value)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}