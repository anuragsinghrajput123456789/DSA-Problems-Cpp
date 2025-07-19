#include<bits/stdc++.h>
using namespace std; 
int main(){
  
 int count = 1; 
 for(int i=0; i<5; i++){
   for(int j=0; j<i; j++){
     cout << count; 
     count++; 
   }
   cout << endl; 
 }

  
  
  
  return 0;
}