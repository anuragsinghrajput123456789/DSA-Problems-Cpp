// function Template for C++
#include<bits/stdc++.h>
using namespace std; 
class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int>s; 
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element); 
        }
        
        while(!s.empty()){
            int x  = s.top(); 
            s.pop(); 
            q.push(x); 
        }
    return q; 
    }
};

int main(){


    
    return 0; 
}