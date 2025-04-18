#include<bits/stdc++.h>
using namespace std;

int largestRowSum(int arr[][3],int row,int col){
    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum+= arr[i][j];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}

int largestColSum(int arr[][3],int row,int col){
    int maxi = INT_MIN;
    int colIndex = -1;

    for(int j=0; j<col; j++){
        int sum = 0;
        for(int i=0; i<row; i++){
            sum+= arr[i][j];
        }
        if(sum > maxi){
            maxi = sum;
            colIndex = j;
        }
    }
    cout << "the maximum column sum is " << maxi << endl;
    return colIndex;
}

void printWaveForm(int arr[][3],int row,int col){
    for(int j=0; j<col; j++){
        if((j%2) == 0){
            //even -> top to bottom
            for(int i=0; i<row; i++){
                cout << arr[i][j] << " ";
            }
        }
        else{
            //odd -> bottom to top
            for(int i=row-1; i>=0; i--){
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void print2D(int arr[][3],int row,int col){
    cout << "Original Array:" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool binary_search2D(int arr[][3],int row,int col,int target){
    int s = 0, e = (row * col) - 1;
    int mid = s + (e - s)/2;

    while(s <= e){
        // Corrected formula to get row and column from mid
        int element = arr[mid/col][mid%col];

        if(element == target){
            return true; // Return true (1) for found
        }

        if(target > element){ // Corrected logic: search in the right half
            s = mid + 1;
        }
        else{
            e = mid - 1; // Corrected logic: search in the left half
        }
        mid = s + (e - s)/2;
    }
    return false; // Return false (0) for not found
}


int main(){

    int arr[3][3] = {{2,4,7},{10,12,15},{18,20,22}}; // Modified array for binary search (should be sorted)

    print2D(arr,3,3);

    // int ansIndexRow = largestRowSum(arr,3,3);
    // int largestColIndex = largestColSum(arr,3,3);

    cout << "Is 4 present? " << binary_search2D(arr,3,3,4) << endl;
    cout << "Is 13 present? " << binary_search2D(arr,3,3,13) << endl;
    cout << "Is 20 present? " << binary_search2D(arr,3,3,20) << endl;
    cout << "Is 5 present? " << binary_search2D(arr,3,3,5) << endl;

    return 0;
}