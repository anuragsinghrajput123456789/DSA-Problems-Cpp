#include<bits/stdc++.h>
using namespace std; 

int func(int mid,int n,int m){

  long long ans= 1;

  for(int i=1;i<=n;i++){

    if(ans*mid>m) return 0;

    ans = ans * mid;

  }

  if(ans == m){

    return 1;

  }

  return 2;

}

 

int NthRoot(int n, int m) {

  // Write your code here.

  int low = 1;

  int high = m;

  while(low<=high){

    int mid = (low+high)/2;

    int val = func(mid, n, m);

    if(val==1){

      return mid;

    }else if(val == 0){

      high = mid - 1;

    }else{ low = mid + 1; }

  }

  return -1;

}
int main(){


    
    return 0; 
}