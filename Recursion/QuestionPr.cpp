#include<bits/stdc++.h>
using namespace std ;

int fact(int n){
  //base case
  if(n == 0)return 1; 
  return fact(n-1) * n;
}

int power(int n){
  //base case
  if(n == 0)return 1; 
  
  return power(n-1)*2;
}

void counting(int n){
   if(n == 0)return ;   
  
  cout << n << endl; 
  
  //recursive call
  counting(n-1);
}

void reachHome(int src, int dest){
   //base case
   if(src == dest){
     cout << "Reached home" << endl; 
     return ; 
   }
   
   //processing - ek step aage badh jao
   src++;
   
   //recursive call
   reachHome(src,dest);
}

int fib(int n){
  if(n == 0){
    return 0; 
  }
  
  if(n == 1){
    return 1;
  }
  
  return fib(n - 1) + fib(n-2);
}


int main(){
  
  cout << fact(5) << endl; 
  cout << power(5) << endl; 
  
  counting(10);
  
  reachHome(1,10);
  
  
  return 0; 
}
