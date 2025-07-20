#include<bits/stdc++.h>
using namespace std; 
int main(){
  char start = 'A';
  int n=5;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout << start; 
    }
      start += 1;
    cout << endl; 
  }
  
  /*
  out put
  AAAAA
BBBBB
CCCCC
DDDDD
EEEEE
*/
 

  
  return 0; 
}


