#include<bits/stdc++.h>
using namespace std; 

bool isSorted(int *arr,int n){
  //base case
  if(n == 0 || n == 1) return true; 

  //ek condition check kar baki recursion sambhal lega na bhai...
  if(arr[0] > arr[1])return false;

  return isSorted(arr+1,n - 1);
}

bool linearFind(int *arr,int n,int key){
  //base case
  if(n == 1 || n == 0)return true;
  
  //ek condition check kar baki recursion sambhal lega bhai
  if(arr[0] == key) return true; 
  
  //recursive call maroo bhai...
  return linearFind(arr + 1,n - 1,key);
}

int recursiveSum(int *arr,int n){
  //base case
  if(n == 0 || n < 0)return 0; 
  
  //ek case solve karoo bhai...
  return arr[0] + recursiveSum(arr + 1,n - 1);

}

int main(){
  
  
  int arr[] = {1,2,3,4,5};
  
  int n = sizeof(arr)/sizeof(arr[0]);
  
  
  
  cout << recursiveSum(arr,n);
  
  
  
  
  return 0; 
}