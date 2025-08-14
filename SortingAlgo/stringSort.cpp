#include<bits/stdc++.h>
using namespace std;

// This function correctly implements selection sort for an array of integers.
void selectionSort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[minIndex], arr[i]);
    }
}

// This function correctly implements selection sort for a string.
void wordSort(string& s) {
    int n = s.length();
    for(int i = 0; i < n - 1; i++) {
        // Find the index of the smallest character in the unsorted part of the string
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(s[j] < s[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found smallest character with the first character of the unsorted part
        swap(s[minIndex], s[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 8, 5, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    string s = "abcsdjfakgjddkafald";

    // Sort the integer array and print the result
    cout << "Sorted integer array:" << endl;
    selectionSort(arr, n);
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Sort the string and print the result
    cout << "Sorted string:" << endl;
    wordSort(s);
    cout << s << endl;

    return 0;
}