#include<bits/stdc++.h>
using namespace std;

void reverseStr(string &str,int i,int j){

    if(i >= j)
        return;

    swap(str[i],str[j]);

    reverseStr(str,i+1,j-1);
}

bool checkPalindrome(string str,int i,int j){

    if(i >= j)
        return true;

    if(str[i] != str[j])
        return false;

    return checkPalindrome(str,i+1,j-1);
}

int power(int a,int b){

    if(b == 0)
        return 1;

    int ans = power(a,b/2);

    if(b % 2 == 0)
        return ans * ans;

    return a * ans * ans;
}

void bubbleSort(int *arr,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

void bubbleSortRecursion(int *arr,int n){

    if(n == 0 || n == 1)
        return;

    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubbleSortRecursion(arr,n-1);
}

void insertionSort(int *arr,int n){

    for(int i=1;i<n;i++){

        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(){

    string name = "anurag";
    int n = name.length();

    reverseStr(name,0,n-1);

    cout << name << endl;

    int arr[] = {8,9,6,5,1,6,5,4,1};
    n = sizeof(arr)/sizeof(arr[0]);

    bubbleSortRecursion(arr,n);

    for(auto i:arr)
        cout << i << " ";

    cout << endl;

    insertionSort(arr,n);

    for(auto i:arr)
        cout << i << " ";

    return 0;
}