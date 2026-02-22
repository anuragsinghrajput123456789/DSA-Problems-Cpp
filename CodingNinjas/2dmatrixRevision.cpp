
#include<bits/stdc++.h>
using namespace std; 

bool isPresent(int arr[][4], int target, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == target) return true; 
        }
    }
    return false; 
}

void print2darray(int arr[][4], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

int rowWiseSum(int arr[][4], int row, int col){
    int totalSum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            totalSum += arr[i][j];
        }
    }
    return totalSum; 
}

int colSum(int arr[][4], int row, int col){
    int totalSum = 0; 
    for(int j = 0; j < col; j++){
        for(int i = 0; i < row; i++){
            totalSum += arr[i][j];
        }
    }
    return totalSum; 
}

int largestRowSum(int arr[][4], int row, int col){
    int maxi = INT_MIN;
    int rowIndex = -1; 
  
    for(int i = 0; i < row; i++){
        int sum = 0;   // reset for each row
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }

        if(sum > maxi){
            maxi = sum; 
            rowIndex = i; 
        }
    }

    cout << "Row with largest sum: " << rowIndex << endl;
    return maxi; 
}

int main(){
    
    
    
    
    
    
    return 0; 
}