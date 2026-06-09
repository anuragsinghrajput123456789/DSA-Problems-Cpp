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




TreeNode<int>* mergeLL(TreeNode<int>* head1, TreeNode<int>* head2) {

    if (head1 == nullptr)
        return head2;

    if (head2 == nullptr)
        return head1;

    TreeNode<int>* head = nullptr;
    TreeNode<int>* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {

        TreeNode<int>* temp = nullptr;

        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        }
        else {
            temp = head2;
            head2 = head2->right;
        }

        temp->left = tail;

        if (head == nullptr) {
            head = temp;
        }
        else {
            tail->right = temp;
        }

        tail = temp;
    }

    while (head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;

        tail = head1;
        head1 = head1->right;
    }

    while (head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;

        tail = head2;
        head2 = head2->right;
    }

    return head;
}


int main(){



    return 0; 
}