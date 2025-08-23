#include <iostream>
#include <string>
#include <vector> // Good practice to include what you use
using namespace std;

char getMaxi(string s) {
    // An array to count the frequency of each character
    int arr[26] = {0};

    // --- FIX IS HERE ---
    // The loop must run from i = 0 up to (but not including) the string's length.
    // The correct condition is i < s.length()
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int num = 0;

        // Convert character to an index from 0 to 25
        if (ch >= 'a' && ch <= 'z') { // For lowercase
            num = ch - 'a';
        } else { // For uppercase
            num = ch - 'A';
        }
        arr[num]++; // Increment the count for that character
    }

    // Find the character with the maximum frequency
    int maxi = -1;
    int ans_index = 0;
    for (int i = 0; i < 26; i++) {
        if (maxi < arr[i]) {
            ans_index = i;
            maxi = arr[i];
        }
    }

    // Convert the index back to a character
    char finalAns = ans_index + 'a';
    return finalAns;
}

int main() {
    string s = "nuninini";
    cout << "The most frequent character is: " << getMaxi(s) << endl; // Expected: n
    return 0;
}