#include <string>
#include <vector>

class Solution {
private:
    // Helper function to check if two character count arrays are equal.
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false; // If any character count differs, they are not equal.
            }
        }
        return true; // All character counts are the same.
    }

public:
    // Main function to check for the inclusion of a permutation of s1 in s2.
    bool checkInclusion(std::string s1, std::string s2) {
        // Edge case: If s1 is longer than s2, a permutation is impossible.
        if (s1.length() > s2.length()) {
            return false;
        }

        // --- Step 1: Create a character frequency map for s1 ---
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // --- Step 2: Create the first window and its frequency map ---
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        // Populate the frequency map for the initial window in s2.
        while (i < windowSize) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Check if the first window is a permutation of s1.
        if (checkEqual(count1, count2)) {
            return true;
        }

        // --- Step 3: Slide the window across the rest of s2 ---
        while (i < s2.length()) {
            // Add the new character to the window's count.
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            // Remove the old character that is sliding out of the window.
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            // Check if the current window is a permutation.
            if (checkEqual(count1, count2)) {
                return true;
            }
            
            i++; // Move the window forward.
        }

        // If we finish the loop without finding a permutation, it doesn't exist.
        return false;
    }
};
