#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int s,int e,int key){
  
  
  int mid = s + (e - s)/2;
  
  while(s < e){
    if(arr[mid] == key){
      return mid;
    }
    else if(arr[mid] >  key){
      //left me jaa
       e = mid-1; 
    }
    else{
      s = mid+1;
    }
    mid = s + (e - s)/2;
  }
  return -1; 
}

int getPivot(int arr[],int n){
  int s = 0; 
  int e = n-1; 
  int mid = s + (e - s)/2; 
  
  while(s < e){
    if(arr[mid] >= arr[0]){
      s = mid + 1;
    }
    else{
      e = mid; 
    }
    mid = s + (e - s)/2; 
  }
  
  return s; 
}


int find(int arr[],int n,int key){
  int s = 0 , e = n-1; 
  int pivotIndex = getPivot(arr,n);
  
  while(s < e){
    
    if(arr[pivotIndex] < key < arr[e]){
      return binarySearch(arr,n,pivotIndex,n-1,key);
    }
    
    else{
      return binarySearch(arr,n,0,pivotIndex - 1,key);
    }
  }
  return -1; 
}


int main(){
  
  int arr[] = {3,8,10,17,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int key = 10;
  
  if(find(arr,n,key) != -1){
    
  cout << key << " : is  at index = "  << find(arr,n,10);
  }
  else{
    cout << "not presend bhai" ;
  }
  
  cout << endl;
  cout << getPivot(arr,n);
  
  
  
  return 0; 
}
