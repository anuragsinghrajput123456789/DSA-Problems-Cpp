#include<bits/stdc++.h>
using namespace std; 



class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size(); 
        
        int i = 0;
        int j=0;
        int count = 0;
        
        while(i < n && j < n){
            while(i < n && arr[i] != 'P') i++;
            
            while(j < n && arr[j] != 'T') j++;
            
            if((i < n) && (j < n) && abs(i - j) <= k){
                count++; 
                i++; 
                j++;
            }
            
            //edge case dekho bhai abb yaha se tum log bhai...
            else if(j< n && j < i) j++;
            
            else if(i < n &&i < j) i++;
            
        }
        return count; 
    }
};

int main(){



    return 0; 
}