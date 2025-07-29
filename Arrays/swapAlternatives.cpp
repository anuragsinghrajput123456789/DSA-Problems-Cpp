// SWAP ALTERNATIVES IN ARRAYS QUESTION 

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int *arr, int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void alternativeSwap(int *arr,int n){
  for(int i=0; i<n;  i=i+2){
    if((i+1) < n){
      swap(arr[i],arr[i+1]);
    }
  }
}


int main() {
    
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(auto i : arr){
      cout << i << " "; 
    }
    
    cout << endl; 
    
    alternativeSwap(arr,n);
    
    
    for(auto i : arr){
      cout << i <<  " "; 
    }
    
    
    
    return 0;
}
