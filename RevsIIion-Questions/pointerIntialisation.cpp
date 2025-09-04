#include<bits/stdc++.h>
using namespace std; 
int main(){
  
  
  //pointer to int is created and poiting to some garbage address
  // int *p; 
  
  // cout << *p << endl; 
  
  // int a = 2; 
  // int *p = &a; 
  
  
  // cout << *p << endl; 
  
  // int *ptr = &a; 
  // cout << ptr; 
  
  
  // int i = 5; 
  // int *p = 0; 
  // p = &i; 
  
  // cout << *p << endl; 
  // cout << p << endl; 
  
  int num = 5; 
  int a = num; 
  a++;
  cout << a << endl; 
  cout << num << endl;
  
  int *p = &num; 
  
  cout << "before : " << num << endl;
  (*p)++;
  cout << "after " << num << endl; 
  
  int *q = p; 
  cout << p << "--" << q << endl; 
  
  
  //important concept
  int i = 3; 
  int *t = &i; 
  cout << (*t)++ << endl; 
  
  
  
  
  return 0; 
}