#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    pair<bool, int> isSumTreeFast(Node *root)
    {
        if (root == nullptr)
        {
            return {true, 0};
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return {true, root->data};
        }

        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool condition = root->data == (leftAns.second + rightAns.second);

        pair<bool, int> ans;

        if (left && right && condition)
        {
            ans.first = true;
            ans.second = leftAns.second + rightAns.second + root->data;
        }
        else
        {
            ans.first = false;
            ans.second = 0;
        }
        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first;
    }
};

int main()
{

    return 0;
}