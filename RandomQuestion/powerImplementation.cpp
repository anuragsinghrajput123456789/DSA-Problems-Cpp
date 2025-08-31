#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

auto power(auto a,auto b){
  auto sum = 1; 
  for(auto i=1; i<=b; i++){
    sum = sum*a; 
  }
  return sum;
}

int main() {
    int num1 = 54;
    int num2 = 24;

    cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << std::endl;

    // Example with the numbers from your previous code
    int num3 = 12;
    int num4 = 24;
    cout << "The GCD of " << num3 << " and " << num4 << " is: " << gcd(num3, num4) << std::endl;

    cout << power(0.5,0.25);

    return 0;
}
