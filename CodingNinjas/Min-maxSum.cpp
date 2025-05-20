#include <bits/stdc++.h>
using namespace std; 
int sumOfMaxMin(int arr[], int n)
{

    int max = INT_MIN; // max will contain minimum possible  integer value

    int min = INT_MAX; // min will contain maximum passible integer value

    for (int i = 0; i < n; i++)
    {

        if (max < arr[i])
        {

            max = arr[i]; // Assiging value arr[i] to max
        }

        if (min > arr[i])
        {

            min = arr[i];
        }
    }

    int sum = min + max;

    return sum;
}
int main(){


    return 0; 
}