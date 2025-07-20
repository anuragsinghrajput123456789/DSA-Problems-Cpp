#include<bits/stdc++.h>
using namespace std; 
int main(){
  
 int n = 5; 
 char ch = 'A';
 for(int i=0; i<n; i++){
   for(int j=0; j<i; j++){
     cout << ch;
     ch+=1;
   }
   cout << endl; 
 }
 
  /*
  A
BC
DEF
GHIJ*/
  
  return 0; 
}