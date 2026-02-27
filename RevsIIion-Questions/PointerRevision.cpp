
#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"1. Basic pointer\n";
    int a = 10;
    int *p = &a;          // pointer stores address
    cout<<"a value: "<<a<<endl;
    cout<<"address of a: "<<&a<<endl;
    cout<<"p stores: "<<p<<endl;
    cout<<"value using *p: "<<*p<<endl;

    cout<<"\n2. Modify value using pointer\n";
    *p = 20;              // change value via pointer
    cout<<"new a: "<<a<<endl;

    cout<<"\n3. Pointer copy\n";
    int *q = p;           // both point same address
    cout<<"p: "<<p<<" q: "<<q<<endl;
    cout<<"*p: "<<*p<<" *q: "<<*q<<endl;

    cout<<"\n4. Null pointer\n";
    int *r = NULL;        // or int *r = 0;
    if(r == NULL){
        cout<<"r is null pointer\n";
    }

    cout<<"\n5. Pointer and array\n";
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;       // array base address
    cout<<"first element: "<<*ptr<<endl;
    cout<<"second element: "<<*(ptr+1)<<endl;

    cout<<"\n6. Pointer arithmetic\n";
    cout<<*ptr<<endl;
    ptr++;
    cout<<*ptr<<endl;

    cout<<"\n7. Pointer to pointer\n";
    int x = 50;
    int *px = &x;
    int **ppx = &px;
    cout<<"x: "<<x<<endl;
    cout<<"*px: "<<*px<<endl;
    cout<<"**ppx: "<<**ppx<<endl;

    cout<<"\n8. Function with pointer\n";
    auto update = [](int *n){
        *n = *n + 5;
    };
    int num = 5;
    update(&num);
    cout<<"after function: "<<num<<endl;

    cout<<"\n9. Dynamic memory (new delete)\n";
    int *dyn = new int;
    *dyn = 99;
    cout<<"dynamic value: "<<*dyn<<endl;
    delete dyn;

    cout<<"\n10. Size of pointer\n";
    int y = 10;
    int *py = &y;
    cout<<"size of int: "<<sizeof(y)<<endl;
    cout<<"size of pointer: "<<sizeof(py)<<endl;

    return 0;
}