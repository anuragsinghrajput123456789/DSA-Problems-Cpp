#include<bits/stdc++.h>
using namespace std; 
int binarySearch(int arr[],int n,int key){
  int s = 0; 
  int e = n-1; 
  
  int mid = s + (e-s)/2; 
  
  while(s <= e){
    
  
     if(arr[mid] == key){
       return mid;
     }
     
     
     
     if(key > arr[mid]){
       //right part me jayenge bhai...
       s = mid + 1; 
     }
     else{
       
       //left part me jayenge bhai..
        e = mid - 1; 
     }
     
     mid = s + (e - s )/2; 
  
  }
  return -1;
}

void printArr(int arr[],int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << endl; 
  }
}

int main() {
    
    int arr[] = {1,2,3,4,5,6,7,8,9};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 3;
   
   cout << binarySearch(arr,n,k) << endl;
   
   
    return 0;
}