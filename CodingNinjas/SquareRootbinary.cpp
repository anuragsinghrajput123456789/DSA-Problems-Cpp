#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n) {
    int s = 0;
    int e = n / 2;
    int ans = 0;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        long long square = 1LL * mid * mid;

        if (square == n) return mid;

        if (square < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int floorSqrt(int n) {
    if (n < 2) return n;
    return binarySearch(n);
}
