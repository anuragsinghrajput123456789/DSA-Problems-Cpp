#include <bits/stdc++.h>
using namespace std;


void solve(string &str, string &output, int index, vector<string> &ans){

    // base case
    if(index == str.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(str, output, index + 1, ans);

    // include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);

    // backtrack
    output.pop_back();
}

vector<string> subsequences(string str){

    vector<string> ans;
    string output = "";

    solve(str, output, 0, ans);

    return ans;
}


int main(){



    return 0;
}