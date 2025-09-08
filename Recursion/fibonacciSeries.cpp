
#include <bits/stdc++.h>
using namespace std;

// Example function to show recursion (reaching home)
void reachHome(int src, int dest) {
    cout << "source " << src << "  destination " << dest << endl;

    // base case
    if (src == dest) {
        cout << "Pohoch gaya hoon bhai ghar .." << endl;
        return;
    }

    // processing
    src++;

    // recursive call
    reachHome(src, dest);
}

// Recursive Fibonacci (returns nth Fibonacci number)
int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibo(n - 1) + fibo(n - 2);
}

// Function to print Fibonacci series using recursion
void printFiboSeries(int n, int a = 0, int b = 1) {
    if (n <= 0) return;

    cout << a << " ";
    printFiboSeries(n - 1, b, a + b);
}

int main() {
    // Reach home example
    reachHome(1, 5);

    // nth Fibonacci
    int n = 5;
    cout << "\nFibonacci(" << n << ") = " << fibo(n) << endl;

    // Fibonacci series
    int terms = 10;
    cout << "\nFibonacci series of " << terms << " terms: ";
    printFiboSeries(20);
    cout << endl;

   return 0;
}
