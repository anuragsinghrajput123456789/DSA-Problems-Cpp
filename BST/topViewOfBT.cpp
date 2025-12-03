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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        map<int, int> topNode;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            Node *frontNode = temp.first;
            int hd = temp.second;

            // insert only if the horizontal distance is not present
            if (topNode.find(hd) == topNode.end())
            {
                topNode[hd] = frontNode->data;
            }

            if (frontNode->left)
            {
                q.push({frontNode->left, hd - 1});
            }

            if (frontNode->right)
            {
                q.push({frontNode->right, hd + 1});
            }
        }

        for (auto it : topNode)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};