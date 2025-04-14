//MAXIMUM CHAHRACTER IN AN STRING....
#include<bits/stdc++.h>
using namespace std;

char getMaxOccr(string s){
    int arr[26] = {0};

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int num = 0;
        if(ch >= 'a' && ch <= 'z'){
            num = ch - 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            num = ch - 'A';
        }
        arr[num]++; // Increment the count for the corresponding character
    }

    int maxi = -1;
    int ans = -1;
    for(int i=0; i<26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){

    string s = "nnnnnnna";
    char result = getMaxOccr(s);
    cout << result << endl;

    return 0;
}