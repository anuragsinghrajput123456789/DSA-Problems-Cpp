#include <iostream>
#include <numeric> // Include this header for std::gcd in C++17 or later
#include <cmath> 

using namespace std; // For std::pow if you need a general power function

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fixed findLCM function
int findLCM(int a, int b) {
    // Use long long for the product to prevent integer overflow
    long long product = static_cast<long long>(a) * b;
    return product / gcd(a, b);
}

// Power function for integer exponents only
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int num1 = 54;
    int num2 = 24;

    cout << "The LCM of " << num1 << " and " << num2 << " is: " << findLCM(num1, num2) << std::endl;

    return 0;
}