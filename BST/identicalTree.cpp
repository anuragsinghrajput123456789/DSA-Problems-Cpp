#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isIdentical(Node* r1, Node* r2) {
        if (r1 == nullptr && r2 == nullptr) return true;
        if (r1 == nullptr || r2 == nullptr) return false; // one null, one not

        if (r1->data != r2->data) return false;

        bool left = isIdentical(r1->left, r2->left);
        if (!left) return false;

        bool right = isIdentical(r1->right, r2->right);
        return right;
    }
};


int main(){


    

    return 0; 
}