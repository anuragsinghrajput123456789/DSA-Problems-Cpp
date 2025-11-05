#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);  // Initialize all with -1

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                ans[i] = arr[j]; // Found the next smaller element
                break;           // Stop once found
            }
        }
    }

    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s; 
    s.push(-1);
    vector<int> ans(n); 

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
           s.pop();
        }
        // ans is stack top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans; 
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    vector<int> result = nextSmaller(arr);

    cout << "Next Smaller Elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
