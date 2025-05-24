/// REVERSE WORDS IN STRING BHAI....


#include <bits/stdc++.h>
using namespace std;  // for strlen

void reverse(char input[], int start, int end) {

    while (start < end) {

        swap(input[start], input[end]);

        start++;

        end--;

    }

}

 

void reverseStringWordWise(char input[]) {

    // Step 1: Reverse the entire string

    int n = strlen(input);

    reverse(input, 0, n - 1);

 

    // Step 2: Reverse each word in the reversed string

    int start = 0;

    for (int end = 0; end <= n; end++) {

        // When we reach a space or the end of the string

        if (input[end] == ' ' || input[end] == '\0') {

            reverse(input, start, end - 1);

            start = end + 1; // Move to the start of the next word

        }

    }

}


int main(){



    return 0; 
}