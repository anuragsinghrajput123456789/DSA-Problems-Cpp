#include<bits/stdc++.h>

using namespace std; 



class Solution {
 private: 
 int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        std::stack<int> s; // Stores indices of bars
        int maxArea = 0;

        // Iterate through all bars, and one extra iteration to clear the stack
        for (int i = 0; i <= n; ++i) {
            // current_height is 0 when i == n to force processing of remaining bars
            int current_height = (i == n) ? 0 : heights[i];

            // While stack is not empty AND current bar is smaller than or equal to
            // the bar at the top of the stack (meaning the bar at stack.top()
            // can't extend further right than 'i')
            while (!s.empty() && current_height <= heights[s.top()]) {
                int popped_height = heights[s.top()];
                s.pop();

                // Calculate width
                // If stack is empty, it means the popped_height bar extends to the
                // left boundary (index -1)
                // Otherwise, the bar below it in the stack is its left smaller element
                int width;
                if (s.empty()) {
                    width = i; // The current 'i' is the right boundary, and left is effectively -1
                } else {
                    width = i - s.top() - 1; // (right boundary index) - (left boundary index) - 1
                }

                maxArea = std::max(maxArea, popped_height * width);
            }
            // Push current bar's index onto stack
            s.push(i);
        }

        return maxArea;
    }
    
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        
      
        //compute area for first row
        int area = largestRectangleArea(mat[0]); 
        
        
        //baki bachi rowcheck karo bhai
        for(int i=1; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                //row upadate by adding previous row's value
                if(mat[i][j] != 0){
                    // previos row ki values ko row me add kar rahe hai
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(mat[i]));
        }
        
        
        return area; 
        
        
        
        
        
        
        
    }
};

int main(){



    return 0; 
}