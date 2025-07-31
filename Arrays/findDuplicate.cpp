#include<bits/stdc++.h>
using namespace std; 

int findDuplicates(int *arr,int n){
    int ans = 0;
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[j] == arr[j+1]){
        ans = arr[j];
      }
    }
  }
  return ans;
}

int main(){
   
  int arr[] = {1,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  int ans = 0;
  
 
  cout << ans << endl; 
  
  return 0; 
}
