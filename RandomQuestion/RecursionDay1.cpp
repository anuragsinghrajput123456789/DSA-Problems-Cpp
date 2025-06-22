#include<bits/stdc++.h>
using namespace std; 

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


  int main(){


    int arr[] = {1,2,3,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int key = 2;
  
    // cout << sorted(arr,n) << endl;
    // cout << sortedRec(arr,n) << endl;
    // int sum =  RecSum(arr,n);
    
    // cout << sum << endl;
    
    
  
  
    return 0;
  }