#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(a == 0){
    return b; 
  }
  
  if(b == 0){
    return a; 
  }
    
  while(a != b){
      if(a > b){
        a = a - b; 
      }
      else{
        b = b - a;
      }
  }
  return a; 
}

//recursive approach is this...
int gcdRec(int a,int b){
  int ans = -1;
  if(a == 0){
    return b; 
  }
  if(b == 0){
    return a;
  
    
  }
  
  if(a > b){
    ans = gcdRec(a,a-b);
  }
  else{
    ans = gcdRec(a,b-a); 
  }
  
  return ans; 
}

int main(){
  
  cout << gcdRec(12,24);
  
  
  
  
  
  return 0;
}
