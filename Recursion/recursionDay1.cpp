
#include<iostream>

// Use the standard namespace to simplify code
using namespace std;

// This function calculates x raised to the power of ex using recursion.
// x: the base number
// ex: the exponent
int power(int x, int ex) {
    // Base Case: If the exponent is 0, the result is 1.
    // This is the condition that stops the recursion.
    if (ex == 0) return 1;

    // Recursive Step:
    // The function calls itself with a reduced exponent (ex - 1).
    // It returns the product of x and the result of the recursive call.
    // This process repeats until the base case is reached.
    return x * power(x, ex - 1);
}

int fact(int a){
  //base case
  if(a == 0)return 1; 
  
  return fact(a - 1) * a;
  
}
int sum(int n){
  //base case
  if(n == 1)return 1; 
  
  cout << n << endl;
  return n + sum(n - 1);
}

int main() {
    // Define the base and exponent for the calculation.
    int x = 5;
    int ex = 6;

    // Call the recursive power function and print the result.
    // This will calculate 5^6.
    cout << "The result of " << x << " raised to the power of " << ex << " is: " << power(x, ex) << endl;
    cout << fact(5) << endl;
    cout << sum(5) << endl; 
    return 0;
}
