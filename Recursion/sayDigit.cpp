#include<bits/stdc++.h>
using namespace std;

string arr[10] = {
    "zero","one","two","three","four",
    "five","six","seven","eight","nine"
};

void sayDigit(int n){
    
    // base case
    if(n == 0)
        return;

    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayDigit(n);

    cout << arr[digit] << " ";
}

int main(){
    
    int n;
    cin >> n;

    if(n == 0){
        cout << "zero";
        return 0;
    }

    sayDigit(n);

    return 0;
}