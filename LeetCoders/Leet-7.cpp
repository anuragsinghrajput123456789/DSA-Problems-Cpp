#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int reverse(int x) {
       long ans = 0; 
       while(x != 0){
         int digit = x % 10; 
         if((ans > INT_MAX / 10) || (ans < INT_MIN / 10)){
            return 0;
         }
         ans = (ans * 10) + digit; 
         x = x/10;
       }
       
       return int(ans); 
    }
};

int main(){
   

    return 0; 
}