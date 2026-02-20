#include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int arr[26] = {0};
  
  // count characters
  for(int i = 0; i < s.length(); i++){
    char ch = s[i];
    int number = 0;

    if(ch >= 'a' && ch <= 'z'){
      number = ch - 'a';
    }
    else if(ch >= 'A' && ch <= 'Z'){
      number = ch - 'A';
    }

    arr[number]++;
  }

  int maxi = -1;
  int ans = 0;

  // find max occurring char
  for(int i = 0; i < 26; i++){
    if(arr[i] > maxi){
      maxi = arr[i];
      ans = i;
    }
  }

  char finalAns = 'a' + ans;
  return finalAns;
    }
};


int main(){




    return 0; 
}
