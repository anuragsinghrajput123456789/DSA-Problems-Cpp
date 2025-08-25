#include <iostream>
#include <string>

// Using namespace std makes code more concise by avoiding the need to
// prefix standard library elements (like string, cout, endl) with std::
using namespace std;

int main() {
    // The string we want to extract substrings from
    string inputText = "mom";
    int stringLength = inputText.length();

    // Iterate through all possible starting positions for a substring
    for (int startIndex = 0; startIndex < stringLength; startIndex++) {
        // For each starting position, iterate through all possible ending positions
        // An ending position can be the same as the starting position (for a single-character substring)
        // or any character up to the end of the string.
        for (int endIndex = startIndex; endIndex < stringLength; endIndex++) {
            // Calculate the length of the current substring
            // It's the difference between the end and start indices, plus one (because indices are 0-based).
            int substringLength = endIndex - startIndex + 1;

            // Extract the substring using substr() and print it, followed by a new line
            cout << inputText.substr(startIndex, substringLength) << endl;
        }
    }

    return 0; // Indicate that the program finished successfully
}
