#include<bits/stdc++.h>
using namespace std; 

int getKthLargest(vector<int>& arr, int k) {
    int n = arr.size();
    
    // min-heap of size k (keeps k largest subarray sums)
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {          // ? important: start from i, not 0
            sum += arr[j];
            
            if (minHeap.size() < k) {
                minHeap.push(sum);
            }
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }
    return minHeap.top();
}

int main(){



    return 0; 
}