
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits; // Return early if no carry
            }
        }

        // If we reach here, it means all digits were 9
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = sol.plusOne(digits1);
    for (int digit : result1) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 2 4

    vector<int> digits2 = {9, 9, 9};
    vector<int> result2 = sol.plusOne(digits2);
    for (int digit : result2) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 0 0 0

    vector<int> digits3 = {9};
    vector<int> result3 = sol.plusOne(digits3);
    for (int digit : result3) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 0

    return 0;
}