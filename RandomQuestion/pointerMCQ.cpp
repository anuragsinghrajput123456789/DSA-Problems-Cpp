#include<bits/stdc++.h>
using namespace std; 

void update(int **p2){
  // p2 = p2 + 1;
  //kuch change hoga islessequal
  // *p2 = *p2 + 1; 
  
  
  **p2 = **p2 + 1; 
}


int main(){

  //pointer mcq find the answer which will print in this...


//Question 1 :   
  // int first = 8; 
  // int second = 18; 
  // int *ptr = &second;
  // *ptr = 9; 
  // cout << first << "  " << second << endl; 
  
  
  // Question 2 bhai: 
  // int first = 6; 
  // int *p = &first; 
  // int *q = p; 
  // (*q)++;
  // cout << first << endl;
  
  // Question 3 : bhai
  // int f = 8; 
  // int *p = &f; 
  // cout << (*p)++ << endl; 
  // cout << f << endl; 
  
  
  /*
  //Question 4 : 
  int *p = 0; 
  int f = 110;
  *p = f; 
//isme *p = &f; 
  cout << *p << endl; 
  // ouput segementaion fault hai isme bhai...
  
  Question 5 : 
  int first = 8;
  int second = 11; 
  int *third = &second; 
  first = *third; 
  *third= *third + 2; 
  cout << first << second << endl; 
  
  
  
  Question 6 :
  
  float f = 12.5;
  float p = 21.5;
  float * ptr = &f; 
  (*ptr)++; 
  *ptr = p;
  cout << *ptr << " " << f << " " << p << endl; 
  
  Question 7 : 
  
  int arr[5]; 
  int *ptr; 
  cout << sizeof(arr) << " " << sizeof(ptr) << endl; 
  
  //20 || 8
  
  Question 8 : 
  
  int arr[] = {11,21,13,14};
  
  cout << *(arr) << " " << *(arr+1) << endl; 
  cout << (*arr + 1) << endl; 
  cout << (*arr) + 1 << endl;
 
  Question 9 : 
  
  int arr[6] = {11,12,3}; 
  cout << arr << endl; 
  cout << &arr << endl; 
  cout << &arr[0] << endl; 
  
  
  int arr[6] = {11,21,31};
  
  
  int *p = arr; 
  
  cout << p[2] << endl; 
  

  Question 10 : 
  
  int arr[] = {11,12,13,14,15};
  cout << *(arr) << " " << *(arr + 3) << endl;
  
  int arr[] = {11,21,31,41};
  int *ptr = arr++; // symbol tabol me update ni kar sakte hai bhai... 
  
  cout << *ptr << endl;
  
  Question 11 : 
  
  
  
  char ch = 'a'; 
  char *ptr = &ch;
  ch++;
  cout << *ptr << endl; 
  
  
  Question 12 : 
  char arr[] = "abcde"; 
  char *p = &arr[0]; 
  p++; 
  cout << p << endl;
// output : bcde ayega isme...
 
Question 12 : 

char str[] = "babbar"; 
char *p = str;  
cout << str[0] << " " << *p << endl;
*/



  
  return 0; 
}

