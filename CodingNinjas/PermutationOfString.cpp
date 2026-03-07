
#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int index, vector<string> &ans){

    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int i = index; i < str.length(); i++){
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        swap(str[index], str[i]); 
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;

    solve(str, 0, ans);

    sort(ans.begin(), ans.end());   // important step

    return ans;
}

int main(){




    return 0;
}