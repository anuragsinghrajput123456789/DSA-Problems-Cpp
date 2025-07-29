//  CALULATING NCR USING FUNCTIONS IN THIS BABY....

#include<bits/stdc++.h>
using namespace std; 

int fact(int n){
  int ans = 1; 
  
  for(int i=1; i<=n; i++){
    ans = ans * i;
  }
  return ans;
}


int nCr(int n,int r){
  
  int num = fact(n); 
  int denom = (fact(r) * fact(n-r));
  
  return (num/denom);
}

int main(){
  
    int n = 8;
    int m = 2;
    
    cout << nCr(n,m);
  
  
  
  return 0; 
}
