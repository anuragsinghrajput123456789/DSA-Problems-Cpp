
#include<bits/stdc++.h>
using namespace std; 

int powerRec(int n, int exponential) {
    // Base case
    if (exponential == 0) return 1;
    return n * powerRec(n, exponential - 1);
}

int powerLoop(int n, int exponential) {
    int ans = 1; 
    for (int i = 0; i < exponential; i++) {
        ans = ans * n; 
    }
    return ans; 
}

int factorialRec(int x) {
    // Base case
    if (x == 0) return 1;
    return factorialRec(x - 1) * x;
}

int factorialLoop(int x) {
    int ans = 1; 
    for (int i = 1; i <= x; i++) {
        ans = ans * i; 
    }
    return ans; 
}

long long powerOf2(int n){
  //base case
  if(n == 0)return 1; 

  //resucrison relation
  return powerOf2(n - 1) * 2;
}

void print(int n){
  //base case
  if(n == 0)return ; 
  
  //work jo karana hai jitni baar...
  cout << n << endl; 
 
 //now recursion relation baby...
 print(n - 1);
}

int main() {
    
    int n = 8; 
    
    cout << factorialLoop(5) << endl;
    cout << factorialRec(4) << endl;
    cout << powerRec(2, 3) << endl;
    cout << powerLoop(2, 3) << endl;
    cout << "2^" << n << " : " << powerOf2(n) << endl; 
    cout << endl; 
    print(5);  

  
    return 0; 
  
  
}