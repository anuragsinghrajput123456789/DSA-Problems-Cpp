#include <bits/stdc++.h>
using namespace std;

int getMax(int *arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int getMin(int *arr, int n) {
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
        }
    }
    return mini;
}

int getSum(int *arr, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }
    return ans;
}

void reverseArray(int *arr, int n) {
    int s = 0, e = n - 1;
    while (s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void swapAlternates(int *arr, int n) {
    for (int i = 0; i < n - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = 5;

    cout << "Max: " << getMax(arr, n) << endl;
    cout << "Min: " << getMin(arr, n) << endl;
    cout << "Sum: " << getSum(arr, n) << endl;

    reverseArray(arr, n);
    cout << "Reversed: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    swapAlternates(arr, n);
    cout << "Swap Alternates: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
