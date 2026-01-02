#include<bits/stdc++.h>
using namespace std; 



class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
       priority_queue<int> pq; 
       int n = arr.size();
       for(int i=0; i<k; i++){
           pq.push(arr[i]);
       }
       
       //step 2 
       for(int i=k; i<n; i++){
           if(arr[i] < pq.top()){
               pq.pop();
               pq.push(arr[i]);
           }
       }
       
       int ans = pq.top();
       return ans; 
    }
};





int main(){



    return 0; 
}