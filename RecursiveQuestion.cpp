#include<bits/stdc++.h>
#include <string> 

using namespace std;

bool palcheck(const string& str, int s, int e) {  
      if (s > e) {       
         return true;   
       }    if (str[s] != str[e]) {     
              return false;    }   
               return palcheck(str, s + 1, e - 1); 
        }


bool isPalindrome(const string& str) {    
    int len = str.length();    
    return palcheck(str, 0, len - 1);
     }  


     int main(){



        return 0; 
     }