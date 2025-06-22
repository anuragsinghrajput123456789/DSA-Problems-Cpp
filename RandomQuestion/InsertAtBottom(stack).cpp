//INSERT ELEMENT AT THE BOTTOM OF THE stack

#include<bits/stdc++.h>
using namespace std; 

void solve(stack<int>&st,int x){
  //base case
  if(st.empty()){
    st.push(x);
    return ; 
  }
  
  int num = st.top();
  st.pop();
  
  //recursive call
  solve(st,x);
  
  s.push(num);
  
}

int main(){
  
  stack<int>x;
  
  
  
  solve(stack<int>,x);
  
  
  return 0; 
}