//POINTERS PRACTICE QUESTIONS HERE...


#include<bits/stdc++.h>
using namespace std; 
int main(){
  
// int arr[10] = {1,2,3};
// int n = 10;
// int *p = arr; 
 
// cout << "address of the first memory block is :" << arr << endl; 
// cout << &arr[0] << endl; 
// cout << " value at 0th index is " << *arr << endl; 
// cout << *arr + 1 << endl; 
// cout << *(arr+1)<< endl;
// cout << (*arr) + 1 << endl;
 
 
// for(auto i=0; i<n; i++){
//   cout << *(arr+i) << endl; 
// }
 
// int i = 3; 
 
// cout << i[arr] << endl;
 
// int temp[10]= {1,2}; 
 
// cout << sizeof(temp) << endl;
// int *ptr = &temp[0];
// cout << sizeof(ptr) << endl;
// cout << sizeof(*ptr) << endl;
// cout << sizeof(&ptr) << endl; 
 
 
// int a[20] = {1,2,3,4,6,8};
// int *p = &a[0]; 
// cout << "->" << &p << endl; 
// cout << &a[0] << endl; 
// cout << &a << endl; 
// cout << a << endl; 
 
 
// int arr[10]; 
// // arr = arr + 1; not possible


//   int *ptr  = &arr[0];
//   cout << ptr << endl; 
//   ptr = ptr + 1; 
//   cout << ptr << endl;
 
 
 
 
 
 int arr[5] = {1,2,4,5};
 char ch[6] = "abcdf";
 
 cout << arr << endl; 
 cout << ch << endl;
 
 
 
 char *c = &ch[0]; 
 cout << *c << endl;
 cout << (*c) + 1 << endl; 
 cout << (&c + 1) << endl; 
 
 //important ouput me jab p ko print karange tab tak 
 // woh chalenga jab tak usse null character na mille tab tak woh chalenga yaha pe...
 
 
 char temp = 'z'; 
 char *p  = &temp;
 
 cout << p << endl; 
 
 
 
 
 
 
 
 
 
 
 
  return 0; 
}

