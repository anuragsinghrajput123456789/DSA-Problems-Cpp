#include<bits/stdc++.h>
using namespace std; 


bool isSorted(int *arr,int n){

    if(n == 0 || n == 1)
        return true;

    if(arr[0] > arr[1])
        return false;

    return isSorted(arr + 1, n - 1);
}

int arraySum(int arr[],int n){

    if(n == 0)
        return 0;

    return arr[0] + arraySum(arr + 1, n - 1);
}

int arraySum2(int arr[], int n, int i){

    if(i == n)
        return 0;

    return arr[i] + arraySum2(arr, n, i + 1);
}

bool linearSearch(int *arr,int n,int target){

    if(n == 0)
        return false;

    if(arr[0] == target)
        return true;

    return linearSearch(arr + 1, n - 1, target);
}

void print(int arr[],int n){

    if(n == 0)
        return;

    cout << arr[0] << endl;

    print(arr + 1, n - 1);
}

bool recurBinary(int *arr,int s,int e,int target){
   
   //base case
   if(s > e)return false;
   int mid = s + (e - s) / 2;
   if(arr[mid] == target)return true;
   
   int mid = s + (e - s) / 2;
   
   if(arr[mid] < target)return recurBinary(arr,mid + 1, e , target);
   
   return recurBinary(arr,s,mid - 1,target);
}


int main(){

    int arr[] = {1,2,1,9,6,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << arraySum(arr,n) << endl;

    cout << arraySum2(arr,n,3) << endl;

    cout << linearSearch(arr,n,5) << endl;

    print(arr,n);
    
    cout << recurBinary(arr,0,n-1,5);



    return 0;
}