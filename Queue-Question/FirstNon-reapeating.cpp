#include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        unordered_map<char,int> count; 
        queue<int>q;
        string ans = ""; 
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i]; 
            
            //count of character++
            count[ch]++; 
            
            //queu me push kardo bhai..
            q.push(ch); 
            
            while(!q.empty()){
                if(count[q.front()] > 1){
                    ///repeating character hai bhai
                      q.pop();
                }
                else{
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