#include<bits/stdc++.h>
using namespace std; 

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int mini=prices[0];
    int maxprofit=0;
    int n=prices.size();
    for( int i=0;i<n;i++){
         if(prices[i]<mini)mini=prices[i];
         if( prices[i]-mini>maxprofit)maxprofit=prices[i]-mini;
    }
    return maxprofit;
}

int main(){


    return 0; 
}
