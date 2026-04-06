#include<bits/stdc++.h>
using namespace std;

// -------- ARRAY STACK --------
class StackArray {
public:
    int *arr; 
    int topIndex;
    int size; 
    
    StackArray(int size){
        this->size = size; 
        arr = new int[size];
        topIndex = -1;
    }
    
    void push(int data){
        if(topIndex == size - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = data;
    }
    
    void pop(){
        if(topIndex == -1){
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }
    
    int top(){
        if(topIndex == -1){
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[topIndex];
    }
    
    bool isEmpty(){
        return topIndex == -1;
    }

    ~StackArray(){
        delete[] arr;
    }
};

// -------- LINKED LIST STACK --------
class Node {
public:
    int data; 
    Node* next; 
    
    Node(int data){
        this->data = data; 
        this->next = nullptr; 
    }
};

class StackLL {
public:
    Node* topNode;

    StackLL(){
        topNode = nullptr;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = topNode;
        topNode = temp;
    }

    void pop(){
        if(!topNode){
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top(){
        if(!topNode){
            cout << "Stack Empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty(){
        return topNode == nullptr;
    }
};

// -------- MAIN --------
int main(){
    StackArray st(5);
    
    st.push(3);
    st.push(5);
    st.push(6);
    
    cout << st.top() << endl;

    StackLL st2;
    st2.push(10);
    st2.push(20);
    cout << st2.top() << endl;

    return 0; 
}