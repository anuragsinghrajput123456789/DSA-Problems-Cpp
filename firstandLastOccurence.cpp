// First and last occuerence of the element in an array using bs

#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            //left me jaoo rahe hai bhai... hum to yaha me
            e = mid - 1;
        }

        else if (key > arr[mid])
        {
            // right me jaoo bhai..
            s = mid + 1;
        }

        else if (key < arr[mid])
        {
            //left me jaoo bhai..
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
}


int lastOcc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            //right me jaoo rahe hai bhai... hum to yaha me
            s = mid + 1;
        }

        else if (key > arr[mid])
        {
            // right me jaoo bhai..
            s = mid + 1;
        }

        else if (key < arr[mid])
        {
            //left me jaoo bhai..
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
}


int main()
{  

    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

  cout << "firs occerence of 3 at index = " << firstOcc(arr,n,3) << endl;
  cout << "last occerence of 3 at index = " << lastOcc(arr,n,3) << endl; 

    return 0;
}