
//DELTE THE MIDDLE ELEMENT FROM THE STACK 

#include<bits/stdc++.h>
using namespace std; 

void solve(stack<int>&st,int count,int size){
  // base case
  if(count == size/2){
    st.pop();
    return ; 
  }
  
  //storing top element
  int num = st.top();
  st.pop();
  
  
  //recursive call
  solve(st,coun+1,size);
  
  st.push(num);
  
}

void deleteMid(stack<int>&st,int n){
  int count = 0; 
  
  solve(stack<int>st,count,n);
}

int main(){
  
  string str= "Anurag Singh Rajput";
  stack<int> st; 
  
  for(int i=0; i< str.length(); i++){
    char ch = str[i];
    st.push(ch);
  }
  
  string ans = "";
  
  while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
  }
  
  
  cout << ans << endl;
  
  
  
  
  
  
  return 0; 
}