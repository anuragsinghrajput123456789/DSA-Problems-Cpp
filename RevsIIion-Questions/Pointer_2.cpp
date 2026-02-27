
#include<bits/stdc++.h>
using namespace std;

int main(){

    // ---------- INT ARRAY ----------
    int arr[5] = {10,20,30,40,50};

    cout << "INT ARRAY\n";
    cout << "arr address: " << arr << endl;          // address of first element
    cout << "first value: " << *arr << endl;         // 10
    cout << "second value: " << *(arr+1) << endl;    // 20

    int *p = arr;  // pointer to first element
    cout << "using pointer p: " << *p << endl;
    cout << "using pointer p+2: " << *(p+2) << endl; // 30


    // ---------- CHAR ARRAY ----------
    char ch[] = "anurag";

    cout << "\nCHAR ARRAY\n";
    cout << "ch prints string: " << ch << endl;      // anurag
    cout << "address of ch: " << &ch << endl;
    cout << "first char: " << *ch << endl;           // a

    char *cptr = ch;
    cout << "using char pointer: " << cptr << endl;  // anurag
    cout << "second char: " << *(cptr+1) << endl;    // n


    // ---------- STRING OBJECT ----------
    string st = "hello world";

    cout << "\nSTRING OBJECT\n";
    cout << "string value: " << st << endl;

    string *sptr = &st;
    cout << "using string pointer: " << *sptr << endl;

    cout << "first char using string: " << st[0] << endl;


    // ---------- STRING TO CHAR POINTER ----------
    cout << "\nSTRING TO CHAR POINTER\n";
    const char *cp = st.c_str();   // convert string to char pointer

    cout << "char pointer from string: " << cp << endl;
    cout << "first char: " << *cp << endl;


    // ---------- POINTER ARITHMETIC ----------
    cout << "\nPOINTER ARITHMETIC\n";
    int nums[3] = {5,9,7};
    int *ptr = nums;

    cout << *ptr << endl;      // 5
    ptr++;
    cout << *ptr << endl;      // 9
    ptr++;
    cout << *ptr << endl;      // 7


    // ---------- POINTER AND ADDRESS ----------
    cout << "\nPOINTER AND ADDRESS\n";
    int x = 100;
    int *xp = &x;

    cout << "x value: " << x << endl;
    cout << "x address: " << &x << endl;
    cout << "pointer xp: " << xp << endl;
    cout << "value at xp: " << *xp << endl;


    return 0;
}