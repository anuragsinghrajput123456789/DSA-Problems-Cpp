#include <iostream>

int modularExponentiation(int x, int n, int m) {
    long long res = 1;
    long long current_x = x % m; // It's good practice to take modulo of x initially

    while (n > 0) {
        if (n & 1) {
            // If n is odd, multiply the result by the current x and take modulo m
            res = (res * current_x) % m;
        }
        // Square the current x and take modulo m
        current_x = (current_x * current_x) % m;
        
        // Right shift n to divide it by 2
        n = n >> 1;
    }
    return static_cast<int>(res);
}
