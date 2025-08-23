//VALID PALLINDROME QUESITON IN THIS...

#include<iostream>
#include<cstring> // Required for strlen()
#include<algorithm> // Required for std::swap

// It's generally better to include specific headers than <bits/stdc++.h>
using namespace std;

bool validPallindrome(char name[],int len){
  int s= 0; 
  int e = len - 1;
  while(s < e){
    if(name[s++] == name[e--])return false; 
  }
  return true; 
}

int main() {

  char name[20] = "anurag singh rajput";
  
  // Get the actual length of the string using strlen()
  int len = strlen(name);
  
  cout << validPallindrome(name,len);
  

  return 0;
}