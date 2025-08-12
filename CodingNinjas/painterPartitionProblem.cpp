#include<bits/stdc++.h>
#include<vector>
using namespace std; 

bool isPossible(vector<int> &boards, int k, int n, long long int maxDistance) {

    long long int painterCount = 1; // Starting with first painter

    long long int distanceSum = 0;

 

    for (int i = 0; i < n; i++) {

        if (boards[i] + distanceSum <= maxDistance) {

            distanceSum += boards[i];

        } else {

            painterCount++;  //starting with second painter

            if (painterCount > k || boards[i] > maxDistance) {

                return false;

            }

            distanceSum = boards[i];

        }

    }

 

    return true;

}

int findLargestMinDistance(vector<int> &boards, int k)

{

    long long int s = 0;

    long long int sum = 0;

    long long int e;

    long long int ans = -1;

    int n = boards.size();

    for (int i = 0; i < n; i++) {

        sum += boards[i];

    }

    e = sum;

    long long int maxDistance = s + (e - s) / 2;

    while (s <= e) {

        if (isPossible(boards, k, n, maxDistance)) {

            ans = maxDistance;

            e = maxDistance - 1;

        } else {

            s = maxDistance + 1;

        }

        maxDistance = s + (e - s) / 2;

    }

 

    return ans;

}