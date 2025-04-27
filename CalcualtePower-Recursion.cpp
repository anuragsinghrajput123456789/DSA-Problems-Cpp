//CALCULATING POWER USING RECUSRION
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

int powerTime(int num,int power){
  //base case
  if(power == 0){
    return 1; 
  }
  
  //base case exp2
  if(power == 1){
    return num; 
  }
  //RECURSIVE CALL
  //ek case khood solve karlo baki recusrion sambhal lega bhai
  int ans = powerTime(num,power/2);
  
  
  if((power%2) == 0){
    return ans* ans; 
  }
  else{
    return num * ans * ans; 
  }
}



int main(){


   int a,b;
   a = 3,b = 11; 
   int ans = powerTime(a,b); 
   
   cout << a << " Rasied to power " << b  << " is : "  << ans << endl; 
  
  
    return 0;
}