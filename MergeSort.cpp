///MERGE SORT HO RAHI HAI BAHI

#include<bits/stdc++.h>
using namespace std;


void merge(int *arr,int s,int e){

    int mid = s + (e - s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int mainArrayIndex = s;
    int *first = new int[len1];
    int *second = new int[len2];

    //copy the values of the first part of the array
    for(int i=0; i<len1; i++){
        first[i] = arr[s + i];
    }

    // copy the values of the second part of the main array
    for(int i=0; i<len2; i++){
        second[i] = arr[mid + 1 + i];
    }

    //merge the two sorted subarrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }


    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr,int s,int e){

    //base case
    if(s >= e){
        return;
    }

    int mid = s + (e - s)/2;

    //sort the left part
    mergeSort(arr,s,mid);

    //sort the right part
    mergeSort(arr,mid+1,e);

    //merge both sorted parts
    merge(arr,s,e);
}

int main(){

    int arr[] = {8,9,4,2,1,3,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);


    mergeSort(arr,0,n-1);

    for(auto i : arr){
        cout << i << endl;
    }

    return 0;
}