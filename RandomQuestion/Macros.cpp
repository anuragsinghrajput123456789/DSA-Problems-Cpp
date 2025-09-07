#include<bits/stdc++.h>
using namespace std;


// This function is not called in main(), but is provided for reference.
// It takes integers by value, so the original variables in main() are not changed.
void func(int a, int b) {
    a++;
    b++;
    cout << a << b << endl;
}


// An inline function that takes two integers by reference and returns the greater one.
inline int getMax(int &a, int &b) {
    return (a > b) ? a : b;
}

// An inline function that takes two integers by reference.
// It returns 'a' if it's odd, otherwise it returns 'b'.
// The return type 'int' has been added to fix the compilation error.
inline int findOdd(int &a, int &b) {
    // A bitwise AND operation (a & 1) checks if 'a' is odd.
    // If 'a' is odd, its last bit is 1, so (a & 1) is 1 (true).
    return (a & 1) ? a : b;
}


int main() {
    int a = 1, b = 5;
    int ans = 0;


    // Call the getMax function and store the result in ans.
    ans = getMax(a, b);
    cout << ans << endl;


    // Call the findOdd function and store the result in ans.
    ans = findOdd(a, b);
    cout << ans << endl;


    return 0;
}
