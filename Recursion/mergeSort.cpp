#include<bits/stdc++.h>
using namespace std; 

void merge(int *arr,int s,int e){
  
  int mid = (s + e)/2;
  
  int len1 = mid - s + 1;
  int len2 = e - mid; 
  
  vector<int>first(len1);
  vector<int>second(len2);
  
  int mainArrayIndex = s; 
  //copy the valeus of original array in created arrays
  for(int i=0;i<len1; i++){
    first[i] = arr[mainArrayIndex++];
  }
  
  mainArrayIndex = mid + 1; 
  
  for(int i=0; i<len2; i++){
    second[i] = arr[mainArrayIndex++];
  }
  
  //merge 2 sorted arrays bhai..
  int index1 = 0; 
  int index2 = 0; 
  mainArrayIndex = s; 
  
  while(index1 < len1 && index2 < len2){
    if(first[index1] < second[index2]){
      arr[mainArrayIndex++] = first[index1++];
    }
    else{
      arr[mainArrayIndex++] = second[index2++];
    }
  }
   
  while(index1 < len1){
    arr[mainArrayIndex++] = first[index1++];
  }
  
  
  while(index2 < len2){
    arr[mainArrayIndex++] = second[index2++];
  }
  
}

void mergeSort(int *arr,int s,int e){
  
  int mid = s + (e - s)/2; 
  //base case
  if(s >= e)return ;
  
  //left part sort karna hai 
  mergeSort(arr,s,mid);
  
  //right part sort karna hai
  mergeSort(arr,mid+1,e);
  
  //abb merge kar dete hai left or right part karlo
  merge(arr,s,e);
  
}

int main(){
  
  
  int arr[] = {7,8,9,8,4,6,5,19,8,6,5,6,51,6,5,4,8,9,51,31,15,63,16,56,56,13,2,3};
  int n= sizeof(arr)/sizeof(arr[0]);
  
  
  mergeSort(arr,0,n-1);
  
  for(auto i : arr){
    cout << i << endl; 
  }
  
  
  return 0;
}
