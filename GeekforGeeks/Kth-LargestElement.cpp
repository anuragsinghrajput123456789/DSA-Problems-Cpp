#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n || k <= 0) return -1;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }

        for(int i = k; i < n; i++){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution obj;
    cout << obj.kthLargest(arr, k);
    return 0;
}
