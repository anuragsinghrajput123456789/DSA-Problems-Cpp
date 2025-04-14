 //PALLINDROME CHECK
 #include <bits/stdc++.h> 
 #include<string.h>

 

bool specialcharacter(char ch) {

    return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');

}

 

bool checkPalindrome(string s)
{

    // Write your code here.

    for(char& ch : s){

        ch = tolower(ch);

    }

 

    int st = 0;

    int e = s.length()-1;

    while(st < e){

        if(!specialcharacter(s[st])){

            st++;

        }

        else if(!specialcharacter(s[e])){

            e--;

        }

        else{

            if(s[st] != s[e]){

                return false;

            }

            st++;

            e--;

        }

    }

    return true; 

}