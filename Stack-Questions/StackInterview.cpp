//INSERT AT BOTTOM OF THE STACK


#include<bits/stdc++.h>
using namespace std;



void insertAtBottom(stack<int> &st, int element){
  //base case
  if(st.empty()){
      st.push(element); 
      return ; 
  }
  int num = st.top(); 
  st.pop(); 

  //recursive call
  insertAtBottom(st,element);

  st.push(num); 

}


void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
      return ; 
      }

      int num = stack.top(); 
      stack.pop(); 


      //recursive call
      reverseStack(stack); 

      insertAtBottom(stack,num);
}

int main(){


    return 0; 
}