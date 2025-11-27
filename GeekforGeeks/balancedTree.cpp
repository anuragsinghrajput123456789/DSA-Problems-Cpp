#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

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
    // returns {isBalanced, height}
    pair<bool, int> check(Node *root)
    {
        if (root == nullptr)
        {
            return {true, 0};
        }

        pair<bool, int> left = check(root->left);
        pair<bool, int> right = check(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        bool isBal = leftAns && rightAns && diff;
        int height = max(left.second, right.second) + 1;

        return {isBal, height};
    }

public:
    bool isBalanced(Node *root)
    {
        return check(root).first;
    }
};

int main()
{

    return 0;
}