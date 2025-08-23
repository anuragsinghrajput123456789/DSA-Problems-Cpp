#include<iostream>
#include<cstring> // Required for strlen()
#include<algorithm> // Required for std::swap

// It's generally better to include specific headers than <bits/stdc++.h>
using namespace std;

// Corrected the typo in the function name
void reverse(char name[], int n) {
  int s = 0;
  int e = n - 1;
  while (s < e) {
    swap(name[s++], name[e--]);
  }
}

int main() {

  char name[20] = "anurag singh rajput";
  
  // Get the actual length of the string using strlen()
  int len = strlen(name);
  
  // Pass the correct length to the function
  reverse(name, len);
  
  cout << name << endl;

  return 0;
}