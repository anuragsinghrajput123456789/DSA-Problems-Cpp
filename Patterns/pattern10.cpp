#include<bits/stdc++.h>
using namespace std; 
int main(){
  
 int n = 5; 
 
 for(int i=0; i<=n; i++){
   for(int j=0; j<=i; j++){
     char ch = 'A' + i;
     cout << ch;
   }
   cout << endl;
 }
 
 /*
 A
BB
CCC
DDDD
EEEEE
FFFFFF*/
 
  
  
  return 0; 
}