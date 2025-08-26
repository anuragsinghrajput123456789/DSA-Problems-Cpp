#include<iostream> 
#include<climits> // Include for INT_MIN
using namespace std; 

bool isPresent(int arr[][3],int row,int col,int target){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == target){
                return true; 
            }
        }
    }
    return false;
}

void print(int arr[][3],int row,int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " "; // Added a space for readability
        }
        cout << endl;
    }
}

void largestSum(int arr[][3],int row,int col){
    int maxi = INT_MIN;
    int rowIndex = -1; 
    
    for(int i = 0; i < row; i++){
        int sum = 0; 
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }
        
        if(sum > maxi){
            maxi = sum;
            rowIndex = i; // The correct row index is 'i', not 'row'
        }
    }
    cout  << "The maximum row sum is " << maxi << " and is at index " << rowIndex << endl; 
}


int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    print(arr, 3, 3);
    
    largestSum(arr, 3, 3);
    
    return 0;
}