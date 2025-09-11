#include<bits/stdc++.h>
using namespace std; 

// by just using single pointer approach in this 
void rescursionReverseString1(string &str,int i){
  //base case
  int n = str.length();
  if(i >= n/2)return ;
  //ek case khood solve karenge baki apne aap ho jayega na bhai...
  swap(str[i],str[n-i-1]);
  // recursive call mar rahe hai bhai isme to...
  rescursionReverseString1(str,i + 1);
}

bool recursiveCheckPallindrome(string &str,int i,int j){
  if(i > j)return true;
  if(str[i] != str[j])return false;
  return recursiveCheckPallindrome(str,i+1,j-1);
}

bool recrusiveCheckP1(string &str,int i){
  //base case
  int n = str.length();
  if(i >= n/2)return true; 
  if(str[i] != str[n-i-1])return false;
  return recrusiveCheckP1(str,i+1);
}


int main(){
  
  string s = "mom"; 
  int n = s.length();
  
  cout << recrusiveCheckP1(s,0);
  
   
  
  return 0;
}
