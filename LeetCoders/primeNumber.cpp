// FIBONACII SERIES USING LOOP'S
#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int n =2; 
  bool isPrime = 1; 
  
  for(int i=2; i<n; i++){
    if(n%i == 0){
      cout << "Not a prime Number" << endl;
      isPrime = 0;
      break; 
    }
  }
  
  if(isPrime == 0){
    cout << "Not a Prime Number " << endl; 
  }
  else{
    cout << "Is a prime number "<< endl;
  }
 
  
  
  return 0; 
}
