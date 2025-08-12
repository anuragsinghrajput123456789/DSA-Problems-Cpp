#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, long long mid) {
   long long studentCount = 1;
   long long pageSum = 0;

   for(int i = 0; i < n; i++){
      if (arr[i] > mid) {
          return false;
      }

      if (pageSum + arr[i] <= mid){
         pageSum += arr[i];
      }
      else{
         studentCount++;
         if(studentCount > m){
           return false;
         }
         pageSum = arr[i];
      }
   }
   return true;
}


int allocateBooks(vector<int> arr, int n, int m) {
    long long int s = 0;
    long long int sum = 0;
    long long int maxBookPages = 0;
    int n = arr.size();

    if (n == 0 || m == 0 || m > n) {
        return -1;
    }

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if (arr[i] > maxBookPages) {
            maxBookPages = arr[i];
        }
    }

    s = maxBookPages;
    long long int e = sum;
    long long int ans = -1;

    while(s <= e){
       long long int mid = s + (e - s) / 2;
       if(isPossible(arr, n, m, mid)){
          ans = mid;
          e = mid - 1;
       }
       else{
           s = mid + 1;
       }
    }
    return ans;
}

int main(){

    vector<int> arr = {1,3,4,8,9,3,2,1};
    int n = arr.size();
    int m = 2;

    cout << "Minimum of maximum pages a student has to read: " << allocateBooks(arr, n, m) << endl;

    return 0;
}
