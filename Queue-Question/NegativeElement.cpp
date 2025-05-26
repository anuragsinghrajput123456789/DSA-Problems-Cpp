#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq; 
        vector<int> ans; 
        int n = arr.size();
        
        // Process first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // Store answer for the first window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
        
        // Process remaining windows
        for (int i = k; i < n; i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            
            // Add current element if it is negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
            
            // Store the answer
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
    } 
};

int main(){

    return 0; 
}