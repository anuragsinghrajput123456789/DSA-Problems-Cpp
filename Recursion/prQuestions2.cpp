#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Sum of first N numbers
int sumRec(int n) {
    if (n == 0) return 0;
    return n + sumRec(n - 1);
}
int sumLoop(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += i;
    return ans;
}

// 2. Reverse a string
void reverseRec(string &s, int start, int end) {
    if (start >= end) return;
    swap(s[start], s[end]);
    reverseRec(s, start + 1, end - 1);
}
void reverseLoop(string &s) {
    int start = 0, end = s.size() - 1;
    while (start < end) {
        swap(s[start], s[end]);
        start++; end--;
    }
}

// 3. Fibonacci
int fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}
void fibLoop(int n) {
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";
        a = b; b = c;
    }
    cout << endl;
}

// 4. Palindrome check
bool isPalindromeRec(string &s, int start, int end) {
    if (start >= end) return true;
    if (s[start] != s[end]) return false;
    return isPalindromeRec(s, start + 1, end - 1);
}
bool isPalindromeLoop(string &s) {
    int start = 0, end = s.size() - 1;
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++; end--;
    }
    return true;
}

// 5. Print digits of a number
void printDigitsRec(int n) {
    if (n == 0) return;
    printDigitsRec(n / 10);
    cout << n % 10 << " ";
}
void printDigitsLoop(int n) {
    string s = to_string(n);
    for (char c : s) cout << c << " ";
    cout << endl;
}

// 6. Factorial
long long factorialRec(int n) {
    if (n <= 1) return 1;
    return n * factorialRec(n - 1);
}
long long factorialLoop(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

// 7. Power (n^k)
long long powerRec(long long n, int k) {
    if (k == 0) return 1;
    return n * powerRec(n, k - 1);
}
long long powerLoop(long long n, int k) {
    long long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

// 8. GCD (Euclidean Algorithm)
int gcdRec(int a, int b) {
    if (b == 0) return a;
    return gcdRec(b, a % b);
}
int gcdLoop(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 9. Count digits
int countDigitsRec(int n) {
    if (n == 0) return 0;
    return 1 + countDigitsRec(n / 10);
}
int countDigitsLoop(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// 10. Sum of digits
int sumDigitsRec(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigitsRec(n / 10);
}
int sumDigitsLoop(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// 11. Print array elements
void printArrayRec(vector<int> &arr, int i) {
    if (i == arr.size()) return;
    cout << arr[i] << " ";
    printArrayRec(arr, i + 1);
}
void printArrayLoop(vector<int> &arr) {
    for (int x : arr) cout << x << " ";
}

// 12. Max element in array
int maxArrayRec(vector<int> &arr, int i) {
    if (i == arr.size() - 1) return arr[i];
    return max(arr[i], maxArrayRec(arr, i + 1));
}
int maxArrayLoop(vector<int> &arr) {
    int maxi = arr[0];
    for (int x : arr) maxi = max(maxi, x);
    return maxi;
}

int main() {
    int n = 5;

    // 1. Sum
    cout << "Sum Rec (1..5): " << sumRec(n) << endl;
    cout << "Sum Loop (1..5): " << sumLoop(n) << endl << endl;

    // 2. Reverse string
    string s1 = "hello", s2 = "world";
    reverseRec(s1, 0, s1.size() - 1);
    reverseLoop(s2);
    cout << "Reverse Rec (hello): " << s1 << endl;
    cout << "Reverse Loop (world): " << s2 << endl << endl;

    // 3. Fibonacci
    cout << "Fibonacci Rec (first 6): ";
    for (int i = 0; i < 6; i++) cout << fibRec(i) << " ";
    cout << endl;
    cout << "Fibonacci Loop (first 6): ";
    fibLoop(6); cout << endl;

    // 4. Palindrome
    string p1 = "madam", p2 = "hello";
    cout << "Palindrome Rec (madam): " << (isPalindromeRec(p1, 0, p1.size()-1) ? "Yes" : "No") << endl;
    cout << "Palindrome Loop (hello): " << (isPalindromeLoop(p2) ? "Yes" : "No") << endl << endl;

    // 5. Digits
    cout << "Digits Rec (1234): "; printDigitsRec(1234); cout << endl;
    cout << "Digits Loop (5678): "; printDigitsLoop(5678); cout << endl;

    // 6. Factorial
    cout << "Factorial Rec (5!): " << factorialRec(5) << endl;
    cout << "Factorial Loop (5!): " << factorialLoop(5) << endl << endl;

    // 7. Power
    cout << "Power Rec (2^4): " << powerRec(2, 4) << endl;
    cout << "Power Loop (2^4): " << powerLoop(2, 4) << endl << endl;

    // 8. GCD
    cout << "GCD Rec (48,18): " << gcdRec(48, 18) << endl;
    cout << "GCD Loop (48,18): " << gcdLoop(48, 18) << endl << endl;

    // 9. Count digits
    cout << "Count Digits Rec (12345): " << countDigitsRec(12345) << endl;
    cout << "Count Digits Loop (6789): " << countDigitsLoop(6789) << endl << endl;

    // 10. Sum of digits
    cout << "Sum Digits Rec (1234): " << sumDigitsRec(1234) << endl;
    cout << "Sum Digits Loop (5678): " << sumDigitsLoop(5678) << endl << endl;

    // 11. Print array
    vector<int> arr = {1, 7, 3, 9, 2};
    cout << "Array Rec: "; printArrayRec(arr, 0); cout << endl;
    cout << "Array Loop: "; printArrayLoop(arr); cout << endl << endl;

    // 12. Max element
    cout << "Max Rec: " << maxArrayRec(arr, 0) << endl;
    cout << "Max Loop: " << maxArrayLoop(arr) << endl;

    return 0;
}
