
#include<bits/stdc++.h>
using namespace std; 

class node{
public: 
    int data; 
    node* next; 
    
    node(int data){
        this->data = data; 
        this->next = nullptr; 
    }
};

// Reverse LL
node* reverseLL(node* &head){
    node* prev = nullptr; 
    node* curr = head;
    node* forward = nullptr; 
    
    while(curr != nullptr){
        forward = curr->next;
        curr->next = prev; 
        prev = curr; 
        curr = forward;
    }
    return prev;
}

// K reverse
node* Kreverse(node* &head,int k){
    if(head == nullptr) return nullptr;
    
    node* next = nullptr; 
    node* curr = head; 
    node* prev = nullptr; 
    int count = 0; 
    
    while(curr != nullptr && count < k){
        next = curr->next; 
        curr->next = prev; 
        prev = curr;
        curr = next; 
        count++;
    }
    
    if(next != nullptr){
        head->next = Kreverse(next,k);
    }
    
    return prev; 
}

// Check circular
bool checkCircular(node* &head){
    if(head == nullptr) return false; 
    
    node* temp = head->next; 
    
    while(temp != nullptr && temp != head){
        temp = temp->next;
    }
    
    return (temp == head);
}

// Detect loop using map
bool detectLoopMap(node* &head){
    if(head == nullptr) return false; 
    
    map<node*,bool> visited; 
    node* temp = head; 
    
    while(temp != nullptr){
        if(visited[temp]) return true; 
        visited[temp] = true;
        temp = temp->next; 
    }
    return false;
}

// First node of loop (map)
node* firstNodeMap(node* &head){
    if(head == nullptr) return nullptr; 
    
    map<node*,bool> visited; 
    node* temp = head;
    
    while(temp != nullptr){
        if(visited[temp]) return temp;
        visited[temp] = true;
        temp = temp->next; 
    }
    return nullptr;
}

// Floyd detect loop
bool floyedDetectLoop(node* &head){
    if(head == nullptr) return false; 
    
    node* slow = head; 
    node* fast = head; 
    
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next; 
        fast = fast->next->next;
        
        if(slow == fast) return true; 
    }
    return false; 
}

// Find starting node of loop (Floyd)
node* startingLoopNode(node* &head){
    if(head == nullptr) return nullptr; 
    
    node* slow = head;
    node* fast = head;
    
    // step 1: detect intersection
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) break;
    }
    
    // no loop
    if(fast == nullptr || fast->next == nullptr) return nullptr;
    
    // step 2: move slow to head
    slow = head;
    
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow; // start of loop
}

// Remove loop
void removeLoop(node* &head){
    if(head == nullptr) return;
    
    node* start = startingLoopNode(head);
    if(start == nullptr) return;
    
    node* temp = start;
    
    while(temp->next != start){
        temp = temp->next;
    }
    
    temp->next = nullptr;
}

int main(){
  
  
  
    return 0; 
}