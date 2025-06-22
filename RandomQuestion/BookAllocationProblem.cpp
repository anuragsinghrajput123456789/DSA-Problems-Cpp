//BOOK ALLOCATION PROBLEM USING BINARY SEARCH HOW TO IMPLEMENT

#include <bits/stdc++.h>  
#include<vector>

bool isPossibleAnswer(int n, int m, long long int mid, int time[]) {

 

  long long int studentCount = 1;

  long long int pageSum = 0;

 

  for (int i = 0; i < m; i++) {

    if (pageSum + time[i] <= mid) {

      pageSum += time[i];

    } else {

 

      studentCount++;

      if (studentCount > n || time[i] > mid) {

        return false;

      }

      pageSum = time[i];

    }

  }

  return true;

}

 

long long ayushGivesNinjatest(int n, int m, int time[]) {

  long long s = 0;

  long long sum = 0;

  for (int i = 0; i < m; i++) {

    sum += time[i];

  }

  long long e = sum;

  long long ans = -1;

  long long int mid = s + (e - s) / 2;

 

  while (s <= e) {

    if (isPossibleAnswer(n, m, mid, time)) {

      ans = mid;

      e = mid - 1;

    } else {

      s = mid + 1;

    }

    mid = s + (e - s) / 2;

  }

  return ans;

}