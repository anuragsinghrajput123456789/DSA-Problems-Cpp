#include<bits/stdc++.h>
using namespace std;

// change value using double pointer
void changeValue(int **ptr){
    **ptr = **ptr + 10;
}

// change pointer address
void changePointer(int **ptr){
    static int x = 100;
    *ptr = &x;   // now pointer will point to x
}

int main(){

    cout<<"--- BASIC DOUBLE POINTER ---\n";
    int i = 5;

    int *p = &i;
    int **p2 = &p;

    cout<<"i: "<<i<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"**p2: "<<**p2<<endl;


    cout<<"\n--- CHANGE VALUE USING DOUBLE POINTER ---\n";
    changeValue(p2);
    cout<<"i after changeValue: "<<i<<endl;   // 15


    cout<<"\n--- CHANGE POINTER ADDRESS ---\n";
    changePointer(p2);

    cout<<"new value using p: "<<*p<<endl;    // 100
    cout<<"value using double pointer: "<<**p2<<endl;


    cout<<"\n--- POINTER ADDRESS UNDERSTANDING ---\n";
    int a = 10;
    int *pa = &a;
    int **ppa = &pa;

    cout<<"a value: "<<a<<endl;
    cout<<"a address: "<<&a<<endl;
    cout<<"pa stores: "<<pa<<endl;
    cout<<"pa address: "<<&pa<<endl;
    cout<<"ppa stores: "<<ppa<<endl;

    cout<<"value using **ppa: "<<**ppa<<endl;

    return 0;
}