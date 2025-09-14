#include <bits/stdc++.h>
using namespace std;  

int powerUsingLoop(int x,int p){
    int ans = 1; 
    for(int i=1; i <= p ; i++){
        ans = ans * x; 
    }
    return ans; 
}

int powerUsingRec(int a,int b){
    // base cases
    if(b == 0) return 1;   // a^0 = 1
    if(b == 1) return a;   // a^1 = a
    
    // recursive call
    int half = powerUsingRec(a, b/2);

    if(b % 2 == 0) {
        return half * half;        // even exponent
    } else {
        return a * half * half;    // odd exponent
    }
}

int main(){
    cout << "Loop method: " << powerUsingLoop(3,11) << endl;
    cout << "Recursion method: " << powerUsingRec(3,11) << endl;
    return 0; 
}
