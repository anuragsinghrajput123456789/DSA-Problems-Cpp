#include<bits/stdc++.h>
using namespace std;


vector<int> pairSum(vector<int> *v1,int target){
  vector<int> ans; 
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i] + arr[j] == target){
        ans.push_back(arr[i]);
        ans.push_back(arr[j]);
      }
    }
  }
  sort(ans.begin(),ans.end());
  return ans; 
}


vector<int> 3sum(vector<int> *v1,int target){
  vector<int> ans; 
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
          if(arr[i] + arr[j] == target){
              ans.push_back(arr[i]);
              ans.push_back(arr[j]);
              ans.push_back(arr[k]);
         }
      }
    }
  }
  sort(ans.begin(),ans.end());
  return ans; 
}



// Optimized function for pairSum using a two-pointer approach
vector<vector<int>> pairSum(vector<int>& arr, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Sort the array
    
    int left = 0;
    int right = arr.size() - 1;
    
    while(left < right){
        int currentSum = arr[left] + arr[right];
        
        if(currentSum == target){
            // Found a pair, add to the answer and move pointers
            ans.push_back({arr[left], arr[right]});
            left++;
            right--;
        } else if (currentSum < target){
            // Sum is too small, need a larger number
            left++;
        } else {
            // Sum is too large, need a smaller number
            right--;
        }
    }
    return ans;
}

// ... rest of the main function code


