#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  int n = 5; 
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      char A = 'A' + i + j - 2;
      cout << A;
    }
    cout << endl;
  }
  
  /*
  ABCDE
BCDEF
CDEFG
DEFGH
EFGHI
*/  
  
  
  return 0; 
}