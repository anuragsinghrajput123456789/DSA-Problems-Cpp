//SORTING SELECTION SORT AND BUBBLE SORT

#include<bits/stdc++.h>
using namespace std; 

void print(int *arr,int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << endl; 
  }
}

void bubble_sort(int arr[],int n){
  for(int i=0; i<n; i++){
    for(int j=0; j< n-i-1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j]; 
        arr[j] = arr[j+1]; 
        arr[j+1]= temp; 
      }
    }
  }
  print(arr,n);
}

void selection_sort(int *arr,int n){
  for(int i=0; i<n; i++){
    int miniIndex = i; 
    for(int j=i+1; j<n; j++){
      if(arr[miniIndex] > arr[j]){
        miniIndex = j; 
      }
    }
    swap(arr[miniIndex], arr[i]);
  }
  print(arr,n);
}




int main(){
  int arr[] = {1,2,3,4,8,9,6,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  
 selection_sort(arr,n);
  
  return 0; 
}