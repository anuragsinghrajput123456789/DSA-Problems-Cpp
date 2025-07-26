#include<algorithm>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)

{

    sort(arr.begin(),arr.end());

    int kthsmall=arr[k-1];

    int kthlarge=arr[arr.size() - k];

    return {kthsmall,kthlarge};

 

}