//FIND PEAK ELEMENT IN THE ARRAY THROUGHT BINARY SEARCH BABY...
#include<bits/stdc++.h>
using namespace std; 


int findPeakElement(vector<int> &arr) {
    // Write your code here
     
     int s = 0; 
     int e = arr.size() - 1; 
    
    int mid = s + (e - s)/2; 
    
    while(s < e){
        if(arr[mid] <= arr[mid + 1] ){
            s = mid + 1; 
        }
        else{
            e = mid; 
        }
         mid = s + (e - s)/2; 
    }
    return s; 

}

int main(){
    vector<int> arr = {1,2,3,1,5,4,3,1};
    cout << findPeakElement(arr);
    
}