// SAY DIGIT THAT ENTERED HERE BABY
#include<bits/stdc++.h>
using namespace std; 
void reachHome(int src,int dest){
    
    
    cout << "source " << src << "--> destination " << dest << endl; 
    //base case
    if(src == dest){
      cout << "pohoch gaya hoon" << endl; 
      return ; 
    }
    
    //processing -> ek step aage badh jaoo bhai
    src++; 
    
    //rescursive call
    //edk case solve karna hai bas
    reachHome(src,dest);
    
}

// int fibonaci(int n){
//   //base case 
//   if(n == 1){
//     return 0; 
//   }
  
//   if(n == 2){
//     return 1; 
//   }
  
//   //recursive call 
//   int ans = fibonaci(n - 1) + fibonaci(n - 2);
//   return ans; 
// }

// int countStairs(int nStairs){
//   //base case
//   if(n < 0){
//     return 0; 
//   }
  
//   if(n == 0){
//     return 1; 
//   }
  
//   //recursive case
//   int ans = fibonaci(n - 1) + fibonaci(n - 2); 
  
//   return ans; 
// }

void sayDigit(int n,string arr[]){
  //base case
  if(n == 0){
    return ; 
  }
  
  //processing
  int digit = n % 10; 
  
  n = n / 10;
  
  //rescursive call; 
  sayDigit(n,arr); 
  
  cout << arr[digit] << endl;
  
}

int main(){
  
  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  
  // int dest = 10; 
  // int src = 1; 
  
  // reachHome(src,dest); 
  // cout << fibonaci(8); 
  
  sayDigit(412, arr); 
  
  return 0; 
}