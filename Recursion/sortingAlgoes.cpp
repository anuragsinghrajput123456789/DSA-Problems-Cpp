#include<bits/stdc++.h>
using namespace std; 
void bubble_sort(int *arr,int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j],arr[j+1]);
      }
    }
  }
}

void bubbleSortRec(int *arr,int n){
  //base case
  //ya to pehle se hi sorted hoga ya koi element ni hoga
  if(n == 0 || n == 1){
    return ; 
  }
  
  // ek case khood solve karo baki ho jayegaa...
  for(int i=0; i<n-1; i++){
    if(arr[i] > arr[i+1]){
      swap(arr[i],arr[i+1]);
    }
  }
  
  
  //now recursive call karte hai..
  bubbleSortRec(arr, n-1);
}

void selectionSort(int *arr,int n){
  for(int i=0; i<n-1; i++){
    int mini = i; 
    for(int j=i+1; j<n; j++){
      if(arr[mini] > arr[j]){
        //updating indices of the values 
        mini = j;
      }
    }
    
    //now finally swaping values
    swap(arr[mini],arr[i]);
  }
}

int main(){
  
  int arr[] = {6,4,4,8,3,2,2};  
  
  int n = sizeof(arr)/sizeof(arr[0]);
  
  bubbleSortRec(arr,n);
  // selectionSort(arr,n);
  
  for(auto i : arr){
    cout << i << endl;
  }
  
  
  return 0;
}
