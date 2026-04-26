#include<bits/stdc++.h>
using namespace std; 
class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        unordered_map<char,int> count; 
        queue<char> q;   // FIX: should be char, not int
        
        string ans = "";
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            
            //adding character in map 
            count[ch]++;
            q.push(ch);
            
            while(!q.empty()){
                if(count[q.front()] > 1){
                    q.pop();
                } else {
                    ans.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
        return ans; 
    }
};

int main(){




    return 0; 
}