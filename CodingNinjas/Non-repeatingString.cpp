#include <bits/stdc++.h> 
using namespace std; 

char firstNonRepeatingCharacter(string str) {

  map<char,int>count; 
  for(auto i=0; i<str.length(); i++){
      count[str[i]]++; 
  }

  for(int i=0; i<str.length(); i++){
     if(count[str[i]] == 1){
       return str[i]; 
     }
  }
  return str[0]; 

}

int main(){




    return 0; 
}