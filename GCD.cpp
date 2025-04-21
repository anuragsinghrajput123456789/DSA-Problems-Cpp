// GCD PROBLEMS IN CPP ISPRIME ALSO
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
  if(n <= 1){
    return false; 
  }
  for(int i=2; i<n; i++){
    if((n%i) == 0){
      return false; 
    }
  }
  return true; 
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    // Optimization: Check divisibility only up to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}


int gcd(int a,int b){
  if(a == 0){
    return b; 
  }
  if(b == 0){
    return a; 
  }
  
  while(a != b){
    if(a > b){
      a = a-b; 
    }
    else{
      b = b - a; 
    }
  }
  return a; 
}



int main(){
  
  
  
  
  return 0;
}
