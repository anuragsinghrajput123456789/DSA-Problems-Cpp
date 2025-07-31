#include<bits/stdc++.h>
using namespace std;


void sort1(int arr[],int n){
  //two pointer appraoch is this...
  int i=0; 
  int j = n-1;
  
  while(i < j){
    
    while(arr[i] == 0){
       i++;
    }
    
    while(arr[j] == 1){
      j--;
    }
    
    //agar yaha phoch gayee hoo, iska mtlb hai 
    swap(arr[i],arr[j]);
    i++;
    j--;
  }
}



int main(){

   int arr[] = {1,1,1,1,0,1,0,1,0,1,0,1,0,1};
   int n = sizeof(arr)/sizeof(arr[0]);
   
   for(auto i : arr){
     cout << i << "--";
   }
   
   sort1(arr,n);
   
   cout << endl;
   
   cout << "after sorting it " << endl; 
  
  
   for(auto i : arr){
     cout << i << "--";
   }
   
  
  
  return 0;
}