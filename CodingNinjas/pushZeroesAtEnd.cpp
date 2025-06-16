#include<bits/stdc++.h>
using namespace std; 

void pushZeroesEnd(int *input, int size) {
    int count = 0; // Count of non-zero elements

    // Traverse the array. If element is non-zero, put it at the
    // current 'count' position and increment count.
    for (int i = 0; i < size; i++) {
        if (input[i] != 0) {
            input[count++] = input[i];
        }
    }

    // Fill remaining positions with zeroes
    while (count < size) {
        input[count++] = 0;
    }
}

int main(){



    

    return 0; 
}