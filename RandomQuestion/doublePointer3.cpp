#include<bits/stdc++.h>
using namespace std; 
void increment(int **p){
   ++(**p); 
}
int main(){


   int num = 100; 
   int *ptr = &num;
   int **p2 = &ptr;  
   
   increment(p2);
   cout << num << endl;

    return 0; 
}