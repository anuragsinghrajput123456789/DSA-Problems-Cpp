//using single pointer approahc
#include<bits/stdc++.h>
using namespace std; 

void reverString(string &str){
  int s = 0; 
  int e = str.length() - 1;
  
  while(s <= e){
    swap(str[s],str[e]);
    s++;
    e--;
  }
}

void recrusiveReverseString(string &str,int s,int e){
  //base case
  if(s > e)return ; 
  
  //ek case khood solve kar le bhai baki rescursion sambhal lega
  swap(str[s],str[e]);
  
  //rescursion call baby
  recrusiveReverseString(str,s + 1,e - 1);
}

// by just using single pointer approach in this 
void rescursionReverseString1(string &str,int i){
  //base case
  int n = str.length();
  
  if(i >= n/2){
    return ;  
  }
  
  //ek case khood solve karenge baki apne aap ho jayega na bhai...
  swap(str[i],str[n-i-1]);
  
  // recursive call mar rahe hai bhai isme to...
  rescursionReverseString1(str,i + 1);
}

int main(){
  
  string s = "anurag singh rajput"; 
  int n = s.length();
  
  // reverString(s);
  
  rescursionReverseString1(s,0);
  cout << s << endl; 
  
  return 0;
}
