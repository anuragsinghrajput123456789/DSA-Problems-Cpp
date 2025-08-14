#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int arr[] = {1,2,3,8,5,2,7,4,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  for(int i=0; i<n; i++){
    int mini = i;
    for(int j=i+1; j<n; j++){
      if(arr[mini] > arr[j])mini = j;
    }
    swap(arr[mini],arr[i]);
  }
   
  //ranged based loop hai bhai yeh to 
  for(auto i : arr){
    cout << i << endl; 
  }
  
  return 0; 
}
