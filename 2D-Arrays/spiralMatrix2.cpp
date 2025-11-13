#include <bits/stdc++.h> 

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 

{

    vector<int> ans;

 

    // Write your code here.

    int row= n;

    int col= m;

    int count=0;

    int totalSize= row*col;

 

    int startingRow=0;

    int startingCol=0;

    int endRow= row-1;

    int endCol= col-1;

 

    while(count<totalSize){

 

//starting row

for(int index= startingCol; index<=endCol && count<totalSize; index++){

    ans.push_back(matrix[startingRow][index]);

count++;

}

startingRow++;

 

//Ending Col

for(int index= startingRow; index<=endRow && count<totalSize; index++){

    ans.push_back(matrix[index][endCol]);

count++;

}

endCol--;

 

//Ending Row

for(int index= endCol; index>=startingCol && count<totalSize; index--){

    ans.push_back(matrix[endRow][index]);

count++;

}

endRow--;

 

//starting col

for(int index= endRow; index>=startingRow && count<totalSize; index--){

    ans.push_back(matrix[index][startingCol]);

count++;

}

startingCol++;

 

    }

    return ans;

 

}

int main(){


    return 0;
}