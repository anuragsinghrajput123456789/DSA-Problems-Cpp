#include<bits/stdc++.h>
using namespace std; 


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> ans;
        if(k<=q.size()){
        for(int i = 0; i<k;i++){
            ans.push(q.front());
            q.pop();
        }
        int size = q.size();
        for(int i = 0; i<k;i++){
            q.push(ans.top());
            ans.pop();
        }
        for(int i = 0; i<size;i++){
            q.push(q.front());
            q.pop();
        }

        return q;
    }
    else{
        return q;
    }
    }
};

int main(){



    return 0; 
}