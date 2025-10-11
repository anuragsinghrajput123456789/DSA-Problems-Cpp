#include <bits/stdc++.h> 
long long evenSumTillN(int n) {
    // Write your code here.

    long long sum = 0; 
    for(long long int i=2; i<=n; i+=2){
       sum += i;
    }
    return sum;
}


int main(){


    return 0; 
}