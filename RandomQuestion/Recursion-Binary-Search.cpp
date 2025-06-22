// BINARY SEARCH USING RECURSION AND NOREMAL BINARY SEARCH 

#include<bits/stdc++.h>
using namespace std;

bool binary_search(int arr[],int n,int key){
   
   int s = 0,e = n-1; 
   
   int mid = s + (e - s)/2; 
  
  while(s <= e){
    if(arr[mid] == key){
        return true; 
    }
    
    if(arr[mid] < key){
      s = mid + 1; 
    }
    else{
      e = mid - 1; 
    }
    mid = s + (e - s)/2; 
  }
  return false; 
}

void print(int arr[],int s,int e){
  for(int i=s; i<=e; i++){
      cout << "---" <<  arr[i] << endl; 
  }
}

bool RecursionBinary_search(int *arr,int s,int e,int key){
  
  
  print(arr,s,e);
  cout << "key is : " <<  key << endl; 
  // base case
  // Element not found here..
  if(s > e) return false; 
  
  int mid = s + (e - s) / 2; 
  cout << "value of mid is : " << mid << endl; 
  //ek case when element is found
  if(arr[mid] == key)return true; 
  
  
  //ek case solve karlo baki recusionn sambhal lega....
  if(arr[mid] < key){
    //right wale part me search karna hai bhai...
   return  RecursionBinary_search(arr,mid + 1,e ,key);
  }
  
  else{
    return RecursionBinary_search(arr,s, mid - 1,key);
  }
  
}
int main(){
  
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  cout << "Element is present or not : " << RecursionBinary_search(arr,0,n-1,91); 
  
  return 0; 
}