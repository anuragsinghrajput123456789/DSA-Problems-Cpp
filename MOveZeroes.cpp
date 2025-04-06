// MOVE ZEROES AT THE LAST IN ARRAY

#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int nonZeroIndex = 0;

    // Iterate through the array and move non-zero elements to the front
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroIndex++] = nums[i];
        }
    }

    // Fill the remaining positions with zeros
    while (nonZeroIndex < n)
    {
        nums[nonZeroIndex++] = 0;
    }
}
int main()
{


  int arr[] = {0,2,0,4,0,6,0,4,0};
  int n = sizeof(arr[0])/sizeof(arr);
  
  moveZeroes(arr,n);




    return 0;
}
