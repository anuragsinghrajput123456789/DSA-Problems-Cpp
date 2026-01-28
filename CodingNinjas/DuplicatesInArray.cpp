#include<bits/stdc++.h>
using namespace std; 

int findDuplicate(vector<int> &arr) 
{
    // Write your code here

    int ans = 0;
    int n = arr.size();

    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }

    for(int i=1; i<arr.size(); i++){
        ans = ans^i; 
    }
    return ans; 
}


int main(){


    return 0; 
}