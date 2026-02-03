
#include<bits/stdc++.h>
using namespace std; 

int search(vector<int>& nums, int n, int target)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    
        int s = 0;
        int e = n - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[s] <= nums[mid]) {
                // Check which part of the array is sorted
                if (nums[s] <= target && target <= nums[mid]) {
                    // Target is in the left part
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[e]) {
                    // Target is in the right part
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        
        return -1;
    }

int main(){


    return 0;
}