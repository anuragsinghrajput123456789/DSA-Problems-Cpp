// Minimum sum
// Difficulty: MediumAccuracy: 17.14%Submissions: 154K+Points: 4
// // Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

class Solution
{
public:
    string addString(string s1, string s2)
    {
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int c = 0;
        string result = "";

        while (i >= 0 || j >= 0 || c > 0)
        {
            int sum = c;

            if (i >= 0)
            {
                sum += (s1[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                sum += (s2[j] - '0');
                j--;
            }

            result.push_back((sum % 10) + '0');
            c = sum / 10;
        }

        // Remove leading zeroes from the end before reversing
        while (!result.empty() && result.back() == '0')
        {
            result.pop_back();
        }

        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }

    string minSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        string s1 = "", s2 = "";
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s1 += to_string(arr[i]);
            }
            else
            {
                s2 += to_string(arr[i]);
            }
        }

        return addString(s1, s2);
    }
};
