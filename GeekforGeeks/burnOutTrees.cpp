#include<bits/stdc++.h>
using namespace std; 

class Node{
    public: 
    int data; 
    Node* right; 
    Node* left; 
    Node(int data){
       this->data = data; 
       right = nullptr; 
       left = nullptr;
    }
};

class Solution {
public:

    // Step 1, create parent mapping and return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &parent) {
        Node* targetNode = nullptr;

        queue<Node*> q;
        q.push(root);
        parent[root] = nullptr;

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(curr->data == target) {
                targetNode = curr;
            }

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    // Step 2, BFS burning process
    int burnTree(Node* start, map<Node*, Node*> &parent) {
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(start);
        visited[start] = true;

        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool burnedAny = false;

            for(int i = 0; i < size; i++) {

                Node* curr = q.front();
                q.pop();

                // left child
                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    burnedAny = true;
                }

                // right child
                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    burnedAny = true;
                }

                // parent
                if(parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                    burnedAny = true;
                }
            }

            if(burnedAny) time++;
        }

        return time;
    }

    // Step 3
    int minTime(Node* root, int target) {
        map<Node*, Node*> parent;

        Node* targetNode = createParentMapping(root, target, parent);

        return burnTree(targetNode, parent);
    }
};


int main(){



    return 0; 
}