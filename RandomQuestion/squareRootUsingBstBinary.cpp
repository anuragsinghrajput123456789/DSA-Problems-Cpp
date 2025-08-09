#include<bits/stdc++.h>
using namespace std;

// This function finds the integer part of the square root
long long int binarySquare(int x){
    if (x < 0) {
        return -1;
    }
    if (x == 0 || x == 1) {
        return x;
    }

    int start = 1;
    int end = x;
    long long int ans = 0; 

    while(start <= end){
        long long int mid = start + (end - start)/2;
        long long int squareCheck = mid * mid;

        if(squareCheck == x){
            return mid;
        }
        
        if(squareCheck < x){
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

// This function adds precision to the integer square root
double morePrecision(int x, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++){
        factor = factor / 10;
        for(double j = ans; j * j < x; j = j + factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n = 101;
    
    // Find the integer part of the square root
    int tempSolve = binarySquare(n);
    cout << "The integer square root of " << n << " is: " << tempSolve << endl;
    
    // Calculate with more precision
    cout << "Answer with precision is: " << fixed << setprecision(3) << morePrecision(n, 3, tempSolve) << endl;
    
    return 0;
}