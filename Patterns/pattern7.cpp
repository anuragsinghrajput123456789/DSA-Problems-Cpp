#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int n=5;
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      char A = 'A' + j - 1;
      cout << A;
    }
    cout << endl; 
  }
 
 /*
 
 pattern output
 
 ABCDE
ABCDE
ABCDE
ABCDE
ABCDE
*/
  
  return 0; 
}


