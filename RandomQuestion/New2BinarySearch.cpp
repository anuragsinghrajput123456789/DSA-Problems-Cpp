#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int n = arr.size();
          
          int st = 0;
          int end = n;
          
          while(st<=end){
              int mid = (st+end)/2;
              
              if(arr[mid] == target){
                  return mid;
              }else if(arr[mid-1] == target){
                  return mid-1;
              }else if(arr[mid+1] == target){
                  return mid+1;
              }else if(target>arr[mid]){
                  st = mid+1;
              }else{
                  end = mid-1;
              }
          }
          return -1;
      }
  };

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int n = arr.size();
          
          int st = 0;
          int end = n;
          
          while(st<=end){
              int mid = (st+end)/2;
              
              if(arr[mid] == target){
                  return mid;
              }else if(arr[mid-1] == target){
                  return mid-1;
              }else if(arr[mid+1] == target){
                  return mid+1;
              }else if(target>arr[mid]){
                  st = mid+1;
              }else{
                  end = mid-1;
              }
          }
          return -1;
      }
  };

  int main(){

    return 0; 
  }