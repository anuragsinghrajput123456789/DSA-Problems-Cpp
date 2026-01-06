#include <bits/stdc++.h> 
using namespace std; 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    //min heap
    priority_queue<int, vector<int>,greater<int>> pq;

  for(auto v:kArrays){
    for(auto i:v){
      pq.push(i);
    }
   }

vector<int> ans;

while(!pq.empty()){
ans.push_back(pq.top());
pq.pop();
}

return ans;
}


int main(){



    return 0; 
}