#include <bits/stdc++.h> 
using namespace std; 

void sortStack(stack<int>&s,int num){
  //base case
  if(s.empty() || (!s.empty() && s.top() < num)){
     s.push(num);
     return ; 
  }

  int n = s.top(); 
  s.pop();

  //recursion call
  sortStack(s,num);

  //last me jaate hui uss number leleo apne sath bhai...
  s.push(n); 

}

void sortStack(stack<int> &stack)
{
    if(stack.empty()){
      return ; 
    }

    int num = stack.top(); 
    stack.pop();

    //recursive call
    sortStack(stack);

    sortStack(stack,num); 
}

int main(){


    return 0; 
}