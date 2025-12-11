#include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            for(int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            for(int v : ans) result.push_back(v);

            leftToRight = !leftToRight;
        }

        return result;
    }
};


int main(){


    return 0; 
}