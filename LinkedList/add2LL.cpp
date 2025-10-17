#include<bits/stdc++.h>
using namespace std; 

class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private: 
    Node* reverseLL(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // Step 1: Reverse both lists to make addition easier
        head1 = reverseLL(head1);
        head2 = reverseLL(head2);

        // Step 2: Initialize pointers
        Node* ansHead = nullptr;
        Node* ansTail = nullptr;
        int carry = 0;

        // Step 3: Single loop to handle everything
        while (head1 != nullptr || head2 != nullptr || carry != 0) {
            int val1 = (head1 ? head1->data : 0);
            int val2 = (head2 ? head2->data : 0);

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            // Create new node for digit
            Node* newNode = new Node(digit);
            if (!ansHead) {
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }

            // Move forward
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }

        // Step 4: Reverse result back
        ansHead = reverseLL(ansHead);
        return ansHead;
    }
};

int main(){




    return 0; 
}