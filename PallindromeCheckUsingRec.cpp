//CHECK pallindromCheck A STRING USING RECURSION
#include<bits/stdc++.h>
using namespace std;



bool pallindromCheck(string &str,int i,int j){
  
  //base case
  if(i > j){
    return true; 
  }
  
  if(str[i] != str[j]){
    return false; 
  }
  else{
    return pallindromCheck(str,i+1,j-1); 
  }
}


int main(){

    string s = "mom";

    cout << pallindromCheck(s,0,s.length() - 1) << endl;


    return 0;
}