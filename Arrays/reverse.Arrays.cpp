#include <bits/stdc++.h>
using namespace std;

void reverseArray(int *arr, int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
