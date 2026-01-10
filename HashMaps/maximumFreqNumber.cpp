#include<bits/stdc++.h>
using namespace std; 


int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxAns = 0;

    // count frequency
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    // first element with max frequency
    for(int i = 0; i < n; i++){
        if(count[arr[i]] == maxFreq){
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}


int main(){




    return 0; 
}