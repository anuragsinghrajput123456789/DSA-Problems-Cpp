#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int n = 4; 
  int i=1; 
  while(i <= n){
    int j=1; 
    while(j <= i){
      cout << (i-j+1);
      j+=1; 
    }
    cout << endl; 
    i+= 1;
  }
  
  
    
  return 0; 
}
