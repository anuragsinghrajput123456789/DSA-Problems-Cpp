#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char, int> count;
        queue<char> q; // Changed to char
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i]; // Defined ch here
            count[ch]++;
            q.push(ch);

            while(!q.empty()) {
                // Check if the front element repeats
                if(count[q.front()] > 1) {
                    q.pop();
                }
                else {
                    // Non-repeating character found
                    ans.push_back(q.front());
                    break;
                }
            }

            if(q.empty()) {
                ans.push_back('#');
            }
        }
        return ans;
    }
};


int main(){

    return 0; 
}