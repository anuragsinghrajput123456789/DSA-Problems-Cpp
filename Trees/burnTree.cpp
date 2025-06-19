// TIME REQUIRED TO BURN A TREE QUESTION 

#include<bits/stdc++.h>
#include <map>
#include <queue>

using namespace std; 


class Solution {
public:
    // Function to create parent mapping for each node and find the target node.
    // Uses Breadth-First Search (BFS) to traverse the tree.
    Node* createParentMapping(Node* root, int target, std::map<Node*, Node*> &nodeToParent) {
        Node* res = nullptr; // To store the target node
        std::queue<Node*> q;
        q.push(root);
        nodeToParent[root] = nullptr; // Root has no parent

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            // Check if the current node is the target node
            if (front->data == target) {
                res = front;
            }

            // If the left child exists, map its parent and add to queue
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            // If the right child exists, map its parent and add to queue
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res; // Return the found target node
    }

    
    int burnTree(Node* targetNode, std::map<Node*, Node*>& nodeToParent) {
        std::map<Node*, bool> visited; // To keep track of burned/visited nodes
        std::queue<Node*> q;

        q.push(targetNode); // Start burning from the target node
        visited[targetNode] = true; // Mark target node as visited/burned

        int time = 0; // Variable to store the elapsed time

        while (!q.empty()) {
            bool newNodesBurnedThisLevel = false; // Flag to check if any new nodes were burned in this time unit
            int size = q.size(); // Number of nodes to process in the current time unit

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                // Check left child: if exists and not visited, burn it
                if (front->left && !visited[front->left]) {
                    newNodesBurnedThisLevel = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                // Check right child: if exists and not visited, burn it
                if (front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                    newNodesBurnedThisLevel = true;
                }

                // Check parent: if exists and not visited, burn it
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    newNodesBurnedThisLevel = true;
                }
            }

            // If any new nodes were burned in this level, increment time
            if (newNodesBurnedThisLevel) {
                time++;
            }
        }
        return time; // Return the total time taken to burn the tree
    }

    // Main function to calculate the minimum time to burn the tree.
    int minTime(Node* root, int target) {
        // Step 1: Create a mapping from each node to its parent.
        std::map<Node*, Node*> nodeToParent;
        // Step 2: Find the target node from where the burning starts.
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        // Step 3: Simulate the burning process and get the minimum time.
        int totalTime = burnTree(targetNode, nodeToParent);
        return totalTime; // Return the calculated time
    }
};


int main(){


    return 0; 
}