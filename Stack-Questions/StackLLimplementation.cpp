#include<bits/stdc++.h>
using namespace std; 


class StackNode{
  private:
    StackNode *top;
    StackNode *next; 
    
  public:
  

    void push(int x) {
        
            StackNode* newNode = new StackNode(x); // creating the node
            newNode -> next = top;
            top = newNode;
    }

    int pop() {
        
        if(top == nullptr)
        {
            return -1;
        }
        else
        {
            StackNode* currNode = top;
            top = top->next;
            int elem = currNode->data;
            delete currNode;
            return elem;
        }
        
    }

    MyStack() { top = NULL; }
};

int main(){

    return 0; 
}