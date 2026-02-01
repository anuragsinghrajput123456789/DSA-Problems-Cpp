#include<bits/stdc++.h>
using namespace std; 

string longestCommonPrefix(vector<string> &arr, int n)
{
    if (n == 0) return "";

    string ans = "";

    for (int i = 0; i < arr[0].size(); i++) {
        char ch = arr[0][i];

        for (int j = 1; j < n; j++) {
            if (i >= arr[j].size() || arr[j][i] != ch)return ans;
        }
        ans.push_back(ch);
    }
    return ans;
}



int main(){


    return 0;
}