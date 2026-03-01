
#include<bits/stdc++.h>
using namespace std;

// -------- BASIC POINTER CHANGE VALUE --------
void changeValue(int *p){
    *p = *p + 10;     // change original value
}

// -------- DOUBLE POINTER CHANGE VALUE --------
void changeValueDouble(int **p){
    **p = **p + 5;    // change original value using double pointer
}

// -------- POINTER SHIFT (danger concept) --------
void shiftPointer(int *p){
    p = p + 1;        // only local copy changes
    cout<<"Inside shiftPointer p: "<<p<<endl;
}

// -------- DOUBLE POINTER SHIFT REAL POINTER --------
void shiftRealPointer(int **p){
    *p = *p + 1;      // real pointer moves
}

// -------- SWAP USING POINTER --------
void swapPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// -------- CREATE ARRAY USING DOUBLE POINTER --------
void createArray(int **arr, int size){
    *arr = new int[size];
    for(int i=0;i<size;i++){
        (*arr)[i] = i*10;
    }
}

int main(){

    cout<<"===== BASIC POINTER ====="<<endl;
    int i = 5;
    int *p = &i;

    cout<<"i: "<<i<<endl;
    cout<<"address of i: "<<&i<<endl;
    cout<<"p (stores address): "<<p<<endl;
    cout<<"*p (value at address): "<<*p<<endl;

    changeValue(p);
    cout<<"After changeValue i: "<<i<<endl;


    cout<<"\n===== DOUBLE POINTER ====="<<endl;
    int **p2 = &p;

    cout<<"i: "<<i<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"**p2: "<<**p2<<endl;

    changeValueDouble(p2);
    cout<<"After double pointer change i: "<<i<<endl;


    cout<<"\n===== POINTER SHIFT LOCAL ====="<<endl;
    cout<<"Before shift p: "<<p<<endl;
    shiftPointer(p);
    cout<<"After shift p: "<<p<<endl;


    cout<<"\n===== REAL POINTER SHIFT USING DOUBLE POINTER ====="<<endl;
    int arr[3] = {10,20,30};
    int *ptr = arr;

    cout<<"Before shift value: "<<*ptr<<endl;
    shiftRealPointer(&ptr);
    cout<<"After shift value: "<<*ptr<<endl;   // now 20


    cout<<"\n===== SWAP USING POINTER ====="<<endl;
    int a = 4, b = 9;
    cout<<"Before swap a:"<<a<<" b:"<<b<<endl;
    swapPointer(&a,&b);
    cout<<"After swap a:"<<a<<" b:"<<b<<endl;


    cout<<"\n===== DYNAMIC ARRAY USING DOUBLE POINTER ====="<<endl;
    int *dynArr = NULL;
    createArray(&dynArr,5);

    for(int i=0;i<5;i++){
        cout<<dynArr[i]<<" ";
    }
    cout<<endl;

    delete [] dynArr;

    return 0;
}