#include<bits/stdc++.h>
using namespace std;

class heap{
  public: 
  int arr[100]; 
  int size = 0;
  
  void insert(int val){
    size = size + 1;
    int index = size; 
    arr[index] = val;
    
    while(index > 1){
      
      int parent = index/2; 
      
      if(arr[parent] < arr[index]){
        swap(arr[parent],arr[index]);
      }
      else{
        return ; 
      }
    }
  }
  
  void print(){
    for(auto i=1; i <= size; i++){
      cout << arr[i] << endl; 
    }
  }
};

int main(){
  
  heap h1;
  
  h1.insert(50);
  h1.insert(55);
  h1.insert(56);
  h1.insert(57);
  h1.print();
  
  
  
  
  
  
  return 0; 
}
