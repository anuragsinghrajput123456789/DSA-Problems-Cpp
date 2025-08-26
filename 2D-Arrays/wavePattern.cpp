#include<iostream>

using namespace std; 

void wavePattern(int arr[][3], int row, int col){
   for(int j = 0; j < col; j++){
     if(j % 2 == 1){ // Odd column index, print bottom to top
       for(int i = row - 1; i >= 0; i--){
         cout << arr[i][j] << " ";
       }
     } else { // Even column index, print top to bottom
       for(int i = 0; i < row; i++){
         cout << arr[i][j] << " ";
       }
     }
   }
}

int main(){
  
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  
  wavePattern(arr, 3, 3);
  
  return 0;   
}