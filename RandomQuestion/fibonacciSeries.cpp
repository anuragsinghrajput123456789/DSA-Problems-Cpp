#include <bits/stdc++.h>
using namespace std;

// Arithmetic progression: 3n + 7
int aP(int n) { 
    return (3 * n + 7);  
}

// Prints first n Fibonacci numbers
void fibonacci(int n) {
    int a = 0; 
    int b = 1; 

    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";

    for (int i = 3; i <= n; i++) {
        int ans = a + b;
        cout << ans << " ";
        a = b;
        b = ans;
    }
    cout << endl;
}

int fib(int n){
  if(n == 1)return 1;
  if(n == 0)return 0; 
  
  return fib(n-1) + fib(n-2); 

}

int main() {
    int n;

   
    // Example usage of Fibonacci
    cout << "Enter number of Fibonacci terms: " << endl;
    n = 10;
    cout << "Fibonacci series: " << endl;
    fibonacci(n);

    return 0; 
}
