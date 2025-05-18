#include <bits/stdc++.h> 
using namespace std; 

void solve(stack<int> &st, int x){
    //base case
    if(st.empty()){
       st.push(x);
       return ; 
    }

     //Ek case solve karlo baki sab recursion sambhal lega bhai
     int num = st.top();
     st.pop();

     //recursive call
     solve(st,x);

     st.push(num);



}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
    

}
int main(){


    return 0; 
}