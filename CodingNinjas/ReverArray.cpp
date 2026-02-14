#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    // Write your code here
    int s = 0;
    int e = arr.size();
    // int e = n-1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{

    return 0;
}