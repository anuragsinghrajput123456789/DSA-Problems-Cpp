#include<bits/stdc++.h>
using namespace std; 

void reverString(string &str){
  int s = 0; 
  int e = str.length() - 1;
  
  while(s <= e){
    swap(str[s],str[e]);
    s++;
    e--;
  }
}

void recrusiveReverseString(string &str,int s,int e){
  //base case
  if(s > e)return ; 
  
  //ek case khood solve kar le bhai baki rescursion sambhal lega
  swap(str[s],str[e]);
  
  //rescursion call baby
  recrusiveReverseString(str,s + 1,e - 1);
}

int main(){
  
  string s = "anurag singh rajput"; 
  int n = s.length();
  
  reverString(s);
  cout << s << endl; 
  // recrusiveReverseString(s,0,n - 1);
  // cout << s << endl; 
  
  return 0;
}
