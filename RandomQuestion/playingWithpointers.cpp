//POINTERS PRACTICE QUESTIONS HERE...


#include<bits/stdc++.h>
using namespace std; 
int main(){
  
int arr1[10] = {1,2,3};
int n = 10;
int *p1 = arr1; 
 
cout << "address of the first memory block is :" << arr1 << endl; 
cout << &arr1[0] << endl; 
cout << " value at 0th index is " << *arr1 << endl; 
cout << *arr1 + 1 << endl; 
cout << *(arr1+1)<< endl;
cout << (*arr1) + 1 << endl;
 
 
for(auto i=0; i<n; i++){
  cout << *(arr1+i) << endl; 
}
 
int i = 3; 
 
cout << i[arr1] << endl;
 
int temp[10]= {1,2}; 
 
cout << sizeof(temp) << endl;
int *ptr = &temp[0];
cout << sizeof(ptr) << endl;
cout << sizeof(*ptr) << endl;
cout << sizeof(&ptr) << endl; 
 
 
int a[20] = {1,2,3,4,6,8};
int *p2 = &a[0]; 
cout << "->" << &p2 << endl; 
cout << &a[0] << endl; 
cout << &a << endl; 
cout << a << endl; 
 
 
int arr2[10]; 
// arr = arr + 1; not possible


  int *ptr2  = &arr2[0];
  cout << ptr2 << endl; 
  ptr2 = ptr2 + 1; 
  cout << ptr2 << endl;
 
 
 
 
 
 int arr3[5] = {1,2,4,5};
 char ch[6] = "abcdf";
 
 cout << arr3 << endl; 
 cout << ch << endl;
 
 
 
 char *c = &ch[0]; 
 cout << *c << endl;
 cout << (*c) + 1 << endl; 
 cout << (&c + 1) << endl; 
 
 //important ouput me jab p ko print karange tab tak 
 // woh chalenga jab tak usse null character na mille tab tak woh chalenga yaha pe...
 
 
 char temp = 'z'; 
 char *cp  = &temp;
 
 cout << static_cast<void*>(cp) << endl; 
 
 
 
 
 
 
 
 
 
 
 
  return 0; 
}

