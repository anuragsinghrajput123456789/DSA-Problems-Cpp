// User function Template for C++
#include<bits/stdc++.h>
#include<vector>
using namespace std; 
class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        int n = arr.size();
        for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
       return true;
    }
};

int main(){


    return 0 ;
}