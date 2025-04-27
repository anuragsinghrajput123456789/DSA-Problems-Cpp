//BUBBLE SORT USING RECUSRION
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr,int n){
  for(int i=0; i<n-1; i++){
    if(arr[i] > arr[i+1]){
       swap(arr[i],arr[i+1]);
    }
  }
}

void recBubble_sort(int *arr,int n){
   
   // base case
   if(n == 0 || n == 1){
     return ; 
   }
   
   //ek case solve karlo baki sab recursin sambhal lega bhai
   for(int i=0; i<n-1; i++){
     if(arr[i] > arr[i+1]){
       swap(arr[i],arr[i+1]);
     }
   }
   
   //baki sab to recursion sambhal lega na bhai
   recBubble_sort(arr,n-1);
}

int main(){


  int arr[] = {10,2,3,4,5,6,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  
  
  recBubble_sort(arr,n);
  
  for(auto i : arr){
    cout << i << endl; 
  }
  
    return 0;
}