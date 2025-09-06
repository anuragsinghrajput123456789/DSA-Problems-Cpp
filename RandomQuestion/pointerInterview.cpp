#include<bits/stdc++.h>
using namespace std;
void update(int& n){
  n++; 
}

// error karega kyoki yeh local variable hai iske bahar iska koi scope ni hai 
int &update2(int a){
  int num = a; 
  
  int &ans = num; 
  return ans; 
}

// error karega kyoki yeh local variable hai iske bahar iska koi scope ni hai 
int *fun(int n){
  int *ptr = &n; 
  return ptr;
}


int main(){
  
  int i = 5;
  //create a referece variable in this
  int &j = i; 
  
  cout << i << endl; 
  i++; 
  cout << i << endl; 
  j++; 
  cout << i << endl;
  
  
  
  
  int n = 5; 
  cout << "Before : " << n <<  endl; 
  update(n);
  cout << "after value : " << n << endl;
  
  update2(n);
  
  char ch = 'q'; 
  cout << sizeof(ch) << endl; 
  char *c = new char; 
  cout << sizeof(c);
  
  
//   create a dynamicaly array 
  int *arr = new int[5];
  

  
  
  
  
  return 0;
}
