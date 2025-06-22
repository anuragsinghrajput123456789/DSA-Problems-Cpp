#include<bits/stdc++.h>
using namespace std;

bool sorted(int *arr,int n){
  for(int i=0; i<n-1; i++){ // Iterate up to n-2 to avoid out-of-bounds access
   if(arr[i] > arr[i+1]){
      return false; // Return false immediately if any adjacent pair is out of order
    }
  }
  return true; // If the loop completes without returning false, the array is sorted
}

bool sortedRec(int *arr,int n){
  //base case
  if(n == 0 || n == 1){
    return true;
  }

  // one case solve karna hai baki recursion sambhal lega bhai...

  if(arr[0] > arr[1]){
    return false;
  }

  //baki sab recursion sambhal lega bhai..
 else{
  bool ans = sortedRec(arr+1,n-1);
  return ans;
 }
}

int RecSum(int *arr,int n){
  if(n == 0){
    return 0; 
  }
  
  if(n == 1){
    return arr[0]; 
  }
  
  //Ek case solve karlo baki case recursion sambhal lega
  int Remaining = RecSum(arr+1, n-1);
  
  //sum of getting remaing baby
  int sum = arr[0] + Remaining;
  
  return sum; 
}


bool search(int *arr,int n,int k){
  
  //base case
  if(n == 0){
    return false; 
  }
  
  //ek case solve karlo 
  if(arr[0] == k){
    return true; 
  }
  else{
   bool reaminingPart = search(arr+1, n-1,k); 
    return reaminingPart;
  }
}

int main(){


  int arr[] = {1,2,3,4};
  int n= sizeof(arr)/sizeof(arr[0]);
  int key = 2;

  // cout << sorted(arr,n) << endl;
  // cout << sortedRec(arr,n) << endl;
  // int sum =  RecSum(arr,n);
  
  // cout << sum << endl;
  
  
  cout << search(arr,n,key); 


  return 0;
}