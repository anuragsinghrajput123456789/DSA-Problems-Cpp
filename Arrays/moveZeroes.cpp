#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int arr[] = {2,0,1,3,0,0,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  // This pointer will keep track of the next non-zero element's position
  int nonZeroIndex = 0; 
  
  // First, move all non-zero elements to the front
  for(int i=0; i<n; i++){
    if(arr[i] != 0){
      // Only swap if the current element is non-zero
      // and it's not already at the correct position
      if (i != nonZeroIndex) {
        swap(arr[i], arr[nonZeroIndex]);
      }
      nonZeroIndex++;
    }
  }
  
  // The rest of the array (from nonZeroIndex to the end) will already be zeros 
  // due to the swap. Alternatively, you can fill them explicitly like this:
  // while(nonZeroIndex < n){
  //   arr[nonZeroIndex++] = 0;
  // }
  
  for(auto i : arr){
    cout << i << endl; 
  }
  
  return 0; 
}