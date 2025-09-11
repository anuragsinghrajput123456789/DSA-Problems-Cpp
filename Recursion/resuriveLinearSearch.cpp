#include<bits/stdc++.h>
using namespace std; 

bool isSorted(int *arr,int n){
  //base case
  if(n == 0 || n == 1) return true; 

  
  //ek condition check kar baki recursion sambhal lega na bhai...
  if(arr[0] > arr[1]){
    return false;
  }

  bool ans = isSorted(arr+1,n - 1);

  return ans; 
}

bool linearFind(int *arr,int n,int key){
  //base case
  if(n == 1 || n == 0)return true;
  
  //ek condition check kar baki recursion sambhal lega bhai
  if(arr[0] == key) return true; 
  
  //recursive call maroo bhai...
  bool ans = linearFind(arr + 1,n - 1,key);
  return ans;
}


int main(){
  
  
  int arr[] = {1,2,64,4,5,6,7,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  if(isSorted(arr,n)){
    cout << "yes it is sorted baby..." << endl; 
  }
  else{
    cout << "not Sorted bhai.." << endl; 
  }
 
 
  
  if(linearFind(arr,n,5)){
    cout << "yes we found it baby " << endl; 
  }
  else{
    cout << "not found baby " << endl; 
  }
  
  
  
  
  return 0; 
}