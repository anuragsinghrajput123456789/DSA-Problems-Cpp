#include<bits/stdc++.h>
using namespace std; 
int main(){
  
 int n = 3; 
 int count = 1; 
 int i=1; 
 while(i<=n){
   int j=1; 
   while(j<=n){
     cout << count; 
     count += 1; 
     j += 1; 
   }
   cout << endl;
   i += 1;
 }
  
  
  
  
  return 0;
}