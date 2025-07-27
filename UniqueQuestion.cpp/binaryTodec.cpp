#include<bits/stdc++.h>
using namespace std;

long long decimalToBinary(long long n){
  long ans = 0;
  int i = 0; 
  
 
 while(n != 0){
   int  bit = n & 1;
   
   ans = ans + (bit * pow(10,i));
   n = n >> 1;
   i++;
 }
 return ans; 
}

int binaryToDecimal(int n){
  
  int i = 0; 
  int ans = 0; 
   
  while(n != 0){
     
     int digit = n % 10; 
     if(digit == 1){
       ans = ans + pow(2,i);
     }
     i++;
     n = n/10; 
   }
   return ans; 
}

int main(){
   
  long long n =  3;
   
  // cout << decimalToBinary(n);
   cout << binaryToDecimal(101);
  
  
  
  
  return 0;
}
