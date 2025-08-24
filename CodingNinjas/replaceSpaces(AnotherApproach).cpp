#include <iostream>
#include <string>
#include <vector> // Often included in <bits/stdc++.h>

using namespace std;

// This function modifies the string directly without creating a new one.
string& replaceSpaces(string &str) {
    // If the string is empty, do nothing.
    if (str.length() == 0) {
        return str;
    }

    // --- Step 1: Count spaces ---
    int space_count = 0;
    for (char c : str) {
        if (c == ' ') {
            space_count++;
        }
    }

    // --- Step 2: Resize the string ---
    int original_length = str.length();
    int new_length = original_length + space_count * 2;
    str.resize(new_length);

    // --- Step 3: Replace from the end ---
    int i = original_length - 1; // Pointer to the end of original content
    int j = new_length - 1;      // Pointer to the end of the new, resized string

    while (i >= 0) {
        if (str[i] == ' ') {
            // Found a space, replace it with '@40'
            str[j] = '0';
            str[j - 1] = '4';
            str[j - 2] = '@';
            j -= 3; // Move the write pointer back 3 positions
            i--;    // Move the read pointer back 1 position
        } else {
            // Not a space, just copy the character
            str[j] = str[i];
            j--;
            i--;
        }
    }
    
    return str;
}

int main() {
    string my_str = "Mr John Smith";
    cout << "Original string: \"" << my_str << "\"" << endl;
    
    replaceSpaces(my_str); // Modify the string in-place
    
    cout << "Modified string: \"" << my_str << "\"" << endl;

    return 0;
}