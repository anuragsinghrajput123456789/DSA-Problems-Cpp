#include<bits/stdc++.h>
using namespace std; 

void reachHome(int src,int dest){
  
  cout << "sources " << src << "  destination " << dest << endl; 
  //base case
  if(src == dest){
    cout << "pohoch gaya hoon bhai ghar .." << endl; 
    return ;
  } 
  
  //processing 
  src++;
  
  //recursive call
  reachHome(src,dest);
}

int fibonacci(int x){
  //base case
  if(x == 0){
    return 0; 
  }
  
  if(x == 1){
    return 1; 
  }
  
  cout << x << endl; 
  
  return fibonacci(x - 1) + fibonacci(x - 2);
}

int main(){
  
  
  cout << fibonacci(5);
  
  
  
  
  
 
 return 0;  
}
