#include<bits/stdc++.h>
using namespace std; 
void print2D(int arr[][3],int row,int col){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout << arr[i][j] << endl;
    }
  }
}
bool linearSearch2D(int arr[][3],int row,int col,int target){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(arr[i][j] == target)return true; 
    }
  }
  return false; 
}

bool binarySearch(int arr[][3],int row,int col,int target){
  int s = 0; 
  int e = (row*col) - 1;
  int mid = s + (e - s)/2; 
  while(s <= e){
   int element = arr[mid/col][mid%col]; 
    if(element == target){
      return true;
    }
    if(element < target){
      s = mid + 1;
    }
    else{
      e = mid - 1; 
    }
     mid = s + (e - s)/2; 
  }
  return false;
}

int main(){
  
  int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int n = 3; 
  
  

  
  
  
  
  return 0; 
}
