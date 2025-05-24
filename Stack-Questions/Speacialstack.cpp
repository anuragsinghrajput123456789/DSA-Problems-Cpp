#include<bits/stdc++.h>
using namespace std; 


class Stack{

public: 
    int top; 
    int size;
    int *arr;

    Stack(int size){
      this->top  = -1; 
      this->arr = new int[size]; 
      this->size = size; 
   }
};



void push(stack<int>& s, int a){
    s.push(a);
}
bool isFull(stack<int>& s,int n){
    return s.size() == n;
}
bool isEmpty(stack<int>& s){
    return s.size() == 0;
}
int pop(stack<int>& s){ 
    s.pop(); // since stack size atleast 1
}
int getMin(stack<int>& s){
    int mini = 100001; 
    while(!isEmpty(s)) {
        if(s.top() < mini)
            mini = s.top();
       s.pop();
    }
    return mini;
}


int main(){
  Stack st(50);
  
  // st.push(200);
  // st.push(100); 


    return 0; 
}