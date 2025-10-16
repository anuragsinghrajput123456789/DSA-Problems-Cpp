#include<bits/stdc++.h>
using namespace std; 
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};

/// @brief 
class Solution{
private: 
    int lengthLL(Node* head) {
        if (!head) return 0;
        return 1 + lengthLL(head->next);
    }

public:
    bool isPalindrome(Node *head) {
        int n = lengthLL(head);
        vector<int> arr;
        arr.reserve(n);
        
        Node* temp = head;
        while (temp) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int s = 0, e = n - 1;
        while (s < e) {
            if (arr[s] != arr[e]) return false;
            s++;
            e--;
        }
        return true;
    }
};
