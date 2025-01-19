//REVERSE A STRING USING STACK  

#include<bits/stdc++.h>
using namespace std; 


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