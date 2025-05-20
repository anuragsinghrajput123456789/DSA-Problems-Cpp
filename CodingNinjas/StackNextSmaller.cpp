#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std; 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st; 
    st.push(-1);
    vector<int> ans(n); 
    
    for(auto i =n-1; i>=0; i--){
      int curr = arr[i]; 
      while(st.top() >= curr){
         st.pop(); 
      }
      //ans is stack ka top
      ans[i] = st.top(); 
      st.push(curr); 
  }
  return ans; 

}

int main(){



    return 0;
}