//Counting elements in two arrays | GfG POTD | 28-06-2025 | GfG Problem of the day | GeeksforGeeks

#include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++){
           int count = 0; 
            for(int j=0; j<m; j++){
                if(b[j] <= a[i]) count++; 
            }
           ans[i] = count; 
        }
        return ans; 
    }
};

int main(){
    
    
    
    
    return 0; 

}