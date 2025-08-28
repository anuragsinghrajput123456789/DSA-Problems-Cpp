#include<bits/stdc++.h>
#include<vector>
using namespace std; 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row * col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while (count < total) {

            // Traverse the top row from left to right
            for (int i = startingCol; i <= endingCol && count < total; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Traverse the rightmost column from top to bottom
            for (int i = startingRow; i <= endingRow && count < total; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // Traverse the bottom row from right to left
            for (int i = endingCol; i >= startingCol && count < total; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // Traverse the leftmost column from bottom to top
            for (int i = endingRow; i >= startingRow && count < total; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};