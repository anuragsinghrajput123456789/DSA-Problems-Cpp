#include<bits/stdc++.h>
#include<vector>
using namespace std; 


class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        // code here
        vector<int>ans;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};

int main(){


    return 0; 
}