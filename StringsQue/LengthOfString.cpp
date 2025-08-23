// FIND THE LENGHT OF THE STRING...

#include<bits/stdc++.h>
using namespace std; 
int getLength(char name[]){
  int cout = 0; 
  for(int i=0;  name[i] != '\0'; i++){
    cout++;    
  }
  return cout;
}
int main(){
 
 char name[20] = "anurag singh rajput"; 
   
  cout <<  getLength(name);
  
  
  return 0; 
}
