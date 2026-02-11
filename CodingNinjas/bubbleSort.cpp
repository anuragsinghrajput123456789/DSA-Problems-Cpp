#include <bits/stdc++.h>
using namespace std; 
void bubbleSort(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    return 0;
}