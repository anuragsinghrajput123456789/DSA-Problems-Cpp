#include <bits/stdc++.h>
#include<vector>
using namespace std; 
bool isPossible(vector<int> &arr, int n, int m, long long mid) { // m is the number of painters (k)
   long long paintersCount = 1;
   long long currentPainterWorkload = 0;

   for(int i=0; i<n; i++){
      // If a single board itself is longer than the allowed 'mid' time, it's impossible.
      if (arr[i] > mid) {
          return false;
      }

      if (currentPainterWorkload + arr[i] <= mid){
         currentPainterWorkload += arr[i];
      }
      else{
          // If current board can't be added, increment painter count and assign to a new painter
          paintersCount++;
          // If we exceed the allowed number of painters (m), it's not possible
          if(paintersCount > m){
            return false;
          }
          currentPainterWorkload = arr[i]; // New painter starts with the current board
      }
   }
   return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    long long int s = 0;
    long long int sum = 0;
    long long int maxBoardLength = 0; // To correctly initialize 's'
    int n = boards.size();

    // Calculate total sum of board lengths and find the maximum single board length
    for(int i=0; i < n; i++){
        sum += boards[i];
        if (boards[i] > maxBoardLength) {
            maxBoardLength = boards[i];
        }
    }

    // The search space for the answer is from the max single board length to the total sum
    s = maxBoardLength;
    long long int e = sum;
    long long int ans = -1;

    while(s <= e){
       long long int mid = s + (e - s)/2; // Calculate mid inside the loop
       // Check if it's possible to paint all boards with 'mid' as max time per painter
       if(isPossible(boards, n, k, mid)){ // Pass 'k' as 'm' in isPossible
          ans = mid; // If possible, 'mid' is a potential answer, try for a smaller time
          e = mid - 1;
       }
       else{
           // If not possible, need more time per painter, so increase lower bound
           s = mid + 1;
       }
    }
    return ans;
}
