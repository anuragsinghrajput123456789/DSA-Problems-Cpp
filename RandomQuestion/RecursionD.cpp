//REEVER A STRING USING RECURSION
#include<bits/stdc++.h>
using namespace std;


void reverse(string &str, int i,int j){
  
  cout << "call recieved for : "  << str << endl; 
  //base case
  if(i > j){
    return ; 
  }
  

  // ek case solve karo ga bakii recursion sambhal lega
  swap(str[i],str[j]);
  i++; 
  j--; 
  
  //Recusrive call; 
  reverse(str,i,j); 
}

int main(){

    string s = "anurag singh rajput";
    
    reverse(s , 0 , s.length()-1);
    cout << s << endl; 


    return 0;
}