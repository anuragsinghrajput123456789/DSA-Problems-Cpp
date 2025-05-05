
#include <bits/stdc++.h> 
using namespace std;
void merge(vector<int>&arr,int s,int e){
    int mid=s+(e-s)/2;
    vector<int>temp;
    int i=s,j=mid+1;
    while(i<=mid && j<=e){
        if(arr[i]>arr[j])temp.push_back(arr[j++]);
        else temp.push_back(arr[i++]);
    }    
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    for(int i=0;i<temp.size();i++){
        arr[s++]=temp[i];
    }
}

void solve(vector<int>&arr,int e,int s=0){
    if(s>=e)return;
    int mid=s+(e-s)/2;
    solve(arr,mid,s);
    solve(arr,e,mid+1);
    merge(arr,s,e);
}

vector<int> mergeSort(vector<int> &arr)
{
  solve(arr,arr.size()-1);
  return arr;
}

int main(){



    return 0; 
}