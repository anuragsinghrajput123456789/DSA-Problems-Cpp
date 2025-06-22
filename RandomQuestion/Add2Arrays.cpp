#include <bits/stdc++.h> 

using namespace std;


 

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {

    int i = n - 1;  // Pointer for array a

    int j = m - 1;  // Pointer for array b

    vector<int> ans;

    int carry = 0;

    

    // Loop until both arrays are exhausted

    while (i >= 0 && j >= 0) {

        int sum = a[i] + b[j] + carry;

        carry = sum / 10;  // Calculate the carry for the next iteration

        sum = sum % 10;    // Get the digit to store in the result

        ans.push_back(sum);

        i--;

        j--;

    }

    

    // If array a has remaining digits

    while (i >= 0) {

        int sum = a[i] + carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);

        i--;

    }


 

    // If array b has remaining digits

    while (j >= 0) {

        int sum = b[j] + carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);

        j--;

    }

    

    // If there's a carry left after processing both arrays

    while (carry != 0) {

        int sum = carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);

    }

    

    // Reverse the result vector (because we process the least significant digit first)

    reverse(ans.begin(), ans.end());

    

    return ans;

}