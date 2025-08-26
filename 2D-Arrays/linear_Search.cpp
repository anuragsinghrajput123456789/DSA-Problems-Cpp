#include<bits/stdc++.h>
using namespace std; 

bool isPresent(int arr[][3],int row,int col,int target){
    for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
       if(arr[i][j] == target){
         return 1; 
       }
    }
  }
  return 0;
}

void print(int arr[][],int row,int col){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << arr[i][j]; 
    }
    cout << endl;
  }
}



int main(){
  
  int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
       cout << arr[i][j]; 
    }
    cout << endl;
  }
  
  if(isPresent(arr,3,3,3)){
    cout << "emelement found" << endl; 
  }
  else{
    cout << "element not presend in this" << endl; 
  }
  
  
  return 0; 
}
