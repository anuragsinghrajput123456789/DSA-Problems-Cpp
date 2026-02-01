#include <bits/stdc++.h>
using namespace std;

int firstOccur(vector<int> &arr, int n, int key)
{
    int ans = -1;

    int s = 0;

    int e = n - 1;

    while (s <= e)
    {

        int mid = s + (e - s) / 2; // Calculate mid

        if (arr[mid] == key)
        {
            ans = mid; // Found the key, update answer

            e = mid - 1; // Move left to find first occurrence
        }
        else if (arr[mid] > key)
        {

            e = mid - 1; // Move left
        }
        else
            s = mid + 1; // Move right
    }
    return ans;
}

int lastOccur(vector<int> &arr, int n, int key)
{

    int ans = -1;

    int s = 0;

    int e = n - 1;

    while (s <= e)
    {

        int mid = s + (e - s) / 2; // Calculate mid

        if (arr[mid] == key)
        {

            ans = mid; // Found the key, update answer

            s = mid + 1; // Move right to find last occurrence
        }
        else if (arr[mid] > key)
        {

            e = mid - 1; // Move left
        }
        else
        {

            s = mid + 1; // Move right
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{

    pair<int, int> p;

    p.first = firstOccur(arr, n, k);

    p.second = lastOccur(arr, n, k);

    return p;
}

int main()
{

    return 0;
}