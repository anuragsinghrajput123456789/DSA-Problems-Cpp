/*You are required to complete this method*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;


class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int deficit = 0; 
        int balance = 0; 
        int start = 0; 
        int n = gas.size();
        
        for(int i=0; i<n; i++){
            balance += gas[i] - cost[i]; 
            if(balance < 0){
                deficit += balance; 
                start = i+1; 
                balance = 0; 
            }
        }
        
        if(deficit + balance >= 0){
            return start; 
        }
        
            return -1;
    }
};

int main(){


    return 0; 
}