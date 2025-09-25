#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate subsets
void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans) {
    // Base case: all elements considered
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // Exclude current element
    solve(nums, output, index + 1, ans);

    // Include current element
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

// Function to return all subsets
vector<vector<int>> subSet(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main() {
    vector<int> arr = {1,2,3};
    
    vector<vector<int>> ans = subSet(arr);
     
     sort(ans.begin(),ans.end());
    // Print all subsets
    for(int i = 0; i < ans.size(); i++){
        cout << "{ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
