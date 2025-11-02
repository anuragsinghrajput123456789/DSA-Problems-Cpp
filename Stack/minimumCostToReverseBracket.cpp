#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
    int n = str.length();

    // if odd length -> impossible to balance
    if (n % 2 != 0) return -1;

    int openCount = 0;  // number of unmatched '{' seen so far
    int cost = 0;       // operations performed so far

    for (char ch : str) {
        if (ch == '{') {
            // we got an opening bracket, increase unmatched opens
            openCount++;
        } else { // ch == '}'
            if (openCount > 0) {
                // there is a matching '{' available -> pair them
                openCount--;
            } else {
                // no unmatched '{' to match this '}' -> flip this '}' to '{'
                // cost 1, and after flipping we have one unmatched '{'
                cost++;
                openCount++;
            }
        }
    }

    // Remaining unmatched '{' must be fixed: two opens can be fixed with one flip
    // e.g. "{{" -> flip one to '}' -> "{}" (cost = 1). So add openCount/2.
    cost += openCount / 2;

    return cost;
}


int main(){


    return 0;
}