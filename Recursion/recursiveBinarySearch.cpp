#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int n,int key){
  int s = 0; 
  int e = n - 1;
  int mid = s + (e - s)/2;

  while(s <= e){
    if(arr[mid] == key){
      return mid;
    }
    
    if(arr[mid] < key){
      //right me jaa bhai..
      s = mid + 1;
    }
    else{
      e = mid - 1; 
    }
  }
  return -1; 
}

bool recursiveBinarySearch(int *arr,int n,int s,int e,int key){
  
  int mid = s + (e - s)/2;
  
  //base case

  if(s > e) return false; 
  
  
  if(arr[mid] == key) return true;
  
  if(arr[mid] < key){
    s = mid + 1;
  }
  else{
    e = mid - 1;
  }
}


int main(){
  int arr[] = {1,2,3,4,5,6,4,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  
  cout << recursiveBinarySearch(arr,n,0,n-1,6);
  
  
  
  
  return 0; 
}
