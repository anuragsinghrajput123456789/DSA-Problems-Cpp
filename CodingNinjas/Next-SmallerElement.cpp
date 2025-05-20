// NEXT SMALLER ELEMENT IN A ARRAY


#include<bits/stdc++.h>
using namespace std; 

int main() {
    int arr[] = {2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int nextSmaller = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                nextSmaller = arr[j];
                break;
            }
        }
        ans.push_back(nextSmaller);
    }

    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}