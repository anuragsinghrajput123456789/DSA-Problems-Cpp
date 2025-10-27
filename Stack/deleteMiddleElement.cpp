 #include <bits/stdc++.h> 

void solve(stack<int>&inputStack,int count, int size){
  if(count == size/2){
     inputStack.pop();
     return ;
  }

   int num = inputStack.top();
   inputStack.pop();

  //recursive call bhai marde yaha pe
  solve(inputStack,count+1,size);
  //recursive call se wapas aa rahe hai bas 
  //them peek element daal do bas
  inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0; 
   solve(inputStack,count,N);
   
}

int main(){
   
    
    

    return 0; 
}