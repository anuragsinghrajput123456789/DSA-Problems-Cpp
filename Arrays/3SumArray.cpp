#include<bits/stdc++.h>
using namespace std; 

vector<int> pairSum(vector<int> *arr,int target,int n){
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


vector<int> 3sum (vector<int> arr,int n,int target){
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


int main(){
  
  vector<int> ans; 
  ans.push_back(1);
  ans.push_back(2);
  ans.push_back(3);
  ans.push_back(4);
  ans.push_back(5);

  vector<int> v1; 
  
  
  



  return 0;
}
