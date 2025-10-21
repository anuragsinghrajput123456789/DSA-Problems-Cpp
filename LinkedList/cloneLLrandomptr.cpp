#include<bits/stdc++.h>
using namespace std; 
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};


class Solution {
  private: 
     void insertAtTail(Node* &head, Node* &tail, int data) {
         Node* newNode = new Node(data);  // ✅ Fixed "node" → "Node"
         if (head == nullptr) {
             head = newNode; 
             tail = newNode; 
         } else {
             tail->next = newNode;
             tail = newNode;
         }
     }
    
  public:
    Node* cloneLinkedList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Clone the list (only next pointers)
        Node* cloneHead = nullptr; 
        Node* cloneTail = nullptr; 
        
        Node* temp = head; 
        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next; 
        }
        
        // Step 2: Create a mapping from original nodes to cloned nodes
        unordered_map<Node*, Node*> oldToNewNode; 
        Node* originalNode = head; 
        Node* cloneNode = cloneHead; 
        
        while (originalNode != nullptr && cloneNode != nullptr) {
            oldToNewNode[originalNode] = cloneNode; 
            originalNode = originalNode->next; 
            cloneNode = cloneNode->next; 
        }
        
        // Step 3: Set up random pointers in the cloned list
        originalNode = head; 
        cloneNode = cloneHead; 
        
        while (originalNode != nullptr) {
            if (originalNode->random != nullptr)
                cloneNode->random = oldToNewNode[originalNode->random];
            else
                cloneNode->random = nullptr;
            
            originalNode = originalNode->next; 
            cloneNode = cloneNode->next; 
        }

        // Step 4: Return the head of the cloned list
        return cloneHead;
    }
};

int main(){
  
  
  
  
  
  return 0; 
}
