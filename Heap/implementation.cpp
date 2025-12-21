#include<bits/stdc++.h>
using namespace std;
class heap{
  public: 
  int arr[100];
  int size = 0; 
  
  heap(){
    int arr[100];
    int size = 0; 
  }
  
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
    for(int i=1; i<=size; i++){
      cout << arr[i] << endl; 
    }
  }
  
  
  
  void deleteinHeap(){
    if(size == 0)return ;
    
    //step 1 : put last element into first index;
    arr[i] = arr[size];
    size--;
    
    //take 
    int i = 1; 
    while(i <  size){
      int leftIndex = 2 * i; 
      int rightIndex = 2 * i + 1;
      
      if(leftIndex < size && arr[i] < arr[leftIndex]){
        swap(arr[i],arr[leftIndex]);
        i = leftIndex; 
      }
      else if(rightIndex < size && arr[i] < arr[rightIndex]){
         swap(arr[i],arr[rightIndex]);
         i = rightIndex;
      }
      else{
        return ;
      }
    }
    
  }
  
};
int main(){
  heap h; 
  h.insert(11);
  h.insert(55);
  h.insert(50);
  h.insert(32);
  h.insert(53);
  
  h.print();
  
  
  
  return 0; 
}
