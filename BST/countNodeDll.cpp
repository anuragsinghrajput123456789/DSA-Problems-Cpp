#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


int countNodes(TreeNode<int>* head) {
    int cnt = 0;

    while (head != nullptr) {
        cnt++;
        head = head->right;
    }

    return cnt;
}

int main(){



    return 0; 
}