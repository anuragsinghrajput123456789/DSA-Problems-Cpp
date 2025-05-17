#include<bits/stdc++.h>
using namespace std;
int main(){
  
  string str = "anurag";
  stack<char> st; 
  
  for(auto i : str){
    char ch = i; 
    st.push(ch);
  }
  
  string ans = "";
  
  while(!st.empty()){
    char ch = st.top();
    ans.push_back(ch);
    
    st.pop(); 
  }
  
  cout << "Reversed string is : " << ans; 
  
  
  
  
  return 0; 
}
