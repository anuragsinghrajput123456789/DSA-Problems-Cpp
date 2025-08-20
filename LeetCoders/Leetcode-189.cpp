// Roatate the array here...
#include<bits/stdc++.h>
using namespace std; 

 void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> temp(n);

        for(int i=0; i<n; i++){
          temp[(i+k)%n] =  nums[i];
        }

       //copy it
         nums = temp; 
    }

int main(){
  int arrr[] = {1,2,3,4,6,8,5,2};  
  int n= sizeof(arrr)/sizeof(arrr[0]);
  
  return 0; 
}

