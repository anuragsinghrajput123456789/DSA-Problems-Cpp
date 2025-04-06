#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int n,int key){
  int s=0,e = n-1; 
  int mid = (s + e)/2;
  
  while(s < e){
    if(arr[mid] == key){
      return mid; 
    }
    
    if(arr[mid] < key){
      //right me jana hai 
      s = mid + 1; 
    }
    else{
      e =  mid - 1; 
    }
    
    mid = (s + e)/2; 
  }
  return -1; 
}

int first_occ(int arr[],int n,int key){
  int s=0,e = n-1; 
  int mid = s + (e - s)/2;
  int ans = -1; 
  
  while(s <= e){
    
    if(arr[mid] == key){
       ans = mid; 
       e = mid - 1; 
    }
    
    if(arr[mid] <  key){
      //right me jana hai
      s = mid + 1; 
    }
    
    else{
      e = mid - 1; 
    }
    
    mid = s + (e - s)/2; 
  }
  return ans; 
}


int last_occ(int arr[],int n,int key){
    int s=0,e = n-1;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e){ // Corrected the loop condition
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int total(int arr[],int n,int k){
  int a = first_occ(arr,n,k);
  int b = last_occ(arr,n,k);
  
  int sum = (b - a) + 1;
  return sum;  
}


int main(){
  
  int arr[] = {1,2,3,3,3,3,3,5};
  
  int n = sizeof(arr)/sizeof(arr[0]);


  cout << first_occ(arr,n,3) << endl;
  cout << last_occ(arr,n,3) << endl; 
  
  cout << "total occurene << " << total(arr,n,3);
  
  
  
  
  
  
  
  return 0; 
}