#include<bits/stdc++.h>

using namespace std;
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