// FIBONACII SERIES USING LOOP'S
#include<bits/stdc++.h>
using namespace std; 
int main(){
  int n= 10;
  int a = 0; 
  int b = 1; 
  
  cout << a << " ";
  cout << b << " ";
  
  for(int i=1; i<=n; i++){
     int next = a+b;
     cout << next << " ";
     
     a = b; 
     b = next;
  }
 
 
  
  
  return 0; 
}
