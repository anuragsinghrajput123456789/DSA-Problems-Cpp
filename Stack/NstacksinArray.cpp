#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr; 
    int *top;
    int *next; 
    int n, s; 
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top array
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next array
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1;

        // Initially, all slots are free
        freespot = 0;
    }

    // Pushes 'x' into the mth stack
    bool push(int x, int m) {
        // Check overflow
        if (freespot == -1) {
            return false;
        }

        // Find index where to push
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Insert element into array
        arr[index] = x;

        // Update next to point to previous top
        next[index] = top[m - 1];

        // Update top of current stack
        top[m - 1] = index;

        return true;
    }

    // Pops top element from mth stack
    int pop(int m) {
        // Check underflow
        if (top[m - 1] == -1) {
            return -1;
        }

        // Find index of top element in stack m
        int index = top[m - 1];

        // Update top to next element in stack
        top[m - 1] = next[index];

        // Update freespot to current index
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
