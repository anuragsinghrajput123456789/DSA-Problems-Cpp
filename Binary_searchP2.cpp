#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n) {
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s; // Return the index of the pivot, not the value.
}

int binarySearch(int arr[], int s, int e, int key) {
    while (s <= e) { // Corrected while condition.
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}

int check(int arr[], int n, int key) {
    int pivotIndex = getPivot(arr, n);

    if (key >= arr[pivotIndex] && key <= arr[n - 1]) {
        return binarySearch(arr, pivotIndex, n - 1, key);
    } else {
        return binarySearch(arr, 0, pivotIndex - 1, key);
    }
}

int square_root(int n){
  int s = 0,e = n;
  long long int mid = s + (e - s)/2; 
  long long int ans = -1; 
  
  while(s <= e){
    
  long long int sqr = mid*mid; 
    
    if(sqr == n){
      return mid;
    }
    
    if(sqr < n){
      //left part
      ans = mid;
      s = mid + 1; 
    }
    
    else{
      e = mid - 1; 
    }
    mid = s + (e - s)/2;
  }
  return ans; 
}

int main() {
    
    int n = 121; 
    
    cout << square_root(n) << endl;
 
    return 0;
}