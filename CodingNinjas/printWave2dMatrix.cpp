#include <bits/stdc++.h>
using namespace std; 

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
  // Write your code here
  vector<int>ans; 

   for(int col = 0; col < mCols; col++){

     if ( col&1 ) {
        //  odd index hai  bottom to top
        
        for (int row = nRows - 1; row >= 0; row--) {
          // cout << arr[row][col] << " ";
          ans.push_back(arr[row][col]);
        }
     }
     else{
        // even hai to top to bottom jana hai

        for (int row=0; row < nRows; row++) {
            // cout << arr[row][col] << " ";
            ans.push_back(arr[row][col]);
        }
     }
   }
   return ans;
}

int main(){



    return 0;
}