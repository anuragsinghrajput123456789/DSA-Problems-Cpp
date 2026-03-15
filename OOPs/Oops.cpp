#include <bits/stdc++.h>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // ── Arithmetic ──────────────────────────────────────────
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex(real*other.real - imag*other.imag,
                       real*other.imag + imag*other.real);
    }

    // ── Comparison ───────────────────────────────────────────
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    bool operator!=(const Complex& other) const {
        return !(*this == other);  // reuse == 
    }

    // ── Unary minus ──────────────────────────────────────────
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // ── Pre-increment  ++c ────────────────────────────────────
    Complex& operator++() {
        ++real; return *this;   // returns reference — efficient
    }
    // ── Post-increment  c++  (dummy int parameter) ───────────
    Complex operator++(int) {
        Complex temp = *this;   // save old value
        ++real;
        return temp;            // returns OLD value by value
    }

    // ── Assignment shorthand ─────────────────────────────────
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // ── Stream output  (must be friend — cout is on the left) ─
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+" << c.imag << "i";
        else             os << c.imag << "i";
        return os;   // return stream to allow chaining: cout << a << b
    }

    // ── Stream input ─────────────────────────────────────────
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex a(3, 4), b(1, -2);

    cout << a + b  << "\n";   // 4+2i
    cout << a * b  << "\n";   // 11-2i
    cout << -a     << "\n";   // -3-4i
    cout << (a == b) << "\n"; // 0 (false)

    Complex c = a;
    cout << c++ << "\n";  // 3+4i  (post: prints OLD, then increments)
    cout << c   << "\n";  // 4+4i  (now incremented)
    cout << ++c << "\n";  // 5+4i  (pre: increments THEN prints)

  
  return 0; 
}