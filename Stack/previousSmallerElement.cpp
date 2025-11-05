#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute force: O(n^2)
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

// Optimized: O(n) using stack
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s; 
    s.push(-1);
    vector<int> ans(n); 

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans; 
}

// Previous smaller element: O(n)
vector<int> previousSmallerElement(vector<int> &arr, int n) {
    stack<int> s; 
    s.push(-1);
    vector<int> ans(n);
  
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans; 
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    vector<int> result1 = nextSmaller(arr);
    vector<int> result2 = nextSmallerElement(arr, n);
    vector<int> result3 = previousSmallerElement(arr, n);

    cout << "Next Smaller (O(n^2)) : ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    cout << "Next Smaller (Stack O(n)) : ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    cout << "Previous Smaller (Stack O(n)) : ";
    for (int val : result3) cout << val << " ";
    cout << endl;

    return 0;
}
