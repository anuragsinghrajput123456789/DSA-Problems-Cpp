#include<bits/stdc++.h>
using namespace std; 

class Stack{
  //properties
public: 
  int *arr; 
  int top; 
  int size; 
  
  //behaviors
  Stack(int size){
    this->size = size; 
    arr = new int[size];
    top = -1; 
  }
  
  void push(int element){
    if(size - top > 1){
      top++; 
      arr[top] = element;
    }
    else{
      cout << "Stack Overflow" << endl; 
    }
  }
  
  void pop(){
    if(top >= 0){
      top--; 
    }
    else{
     cout << "stack is underflow" << endl; 
    }
  }
  
  int peek(){
    if(top >= 0){
      return arr[top]; 
    }
    else{
      cout << "Stack is empty" << endl; 
      return -1; 
    }
  }
  
  
  bool isEmpty(){
    if(top == -1){
      return true; 
    }
    return false; 
  }
  
  bool isFull(){
    if(top - 1 > size){
      return true; 
    }
    return false; 
  }
  
};

int main(){
  
  Stack st(5);
  
  st.push(22); 
  st.push(33); 
  st.push(44); 
  st.push(55);
  st.push(66); 
  
  
  // cout << st.peek() << endl; 
  // st.pop();
  // cout << st.peek();
  
  if(st.isEmpty()){
    cout << "stack is empty mere dost" << endl; 
  }
  else{
    cout << "stack is not empty merre dost" << endl; 
  }
  
  
  
  return 0; 
}
