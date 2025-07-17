#include<bits/stdc++.h>
using namespace std;

class heap{
public: 
    int arr[100];
    int size = 0;
    
    void maxHeap(int val){
        size++; 
        int index = size; 
        arr[index] = val; 
        
        while(index > 1){
            int parent = index/2; 
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent; 
            }
            else{
                return; 
            }
        }
    }
    
    void minHeap(int val){
        size++; 
        int index = size; 
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2; 
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent; 
            }
            else{
                return; 
            }
        }
    }
    
    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete here..." << endl; 
            return; 
        }
        // Step 1: Put last element into first index
        arr[1] = arr[size];
        
        // Step 2: Remove the last element
        size--; 
        
        // Step 3: Take root node to its correct position
        int i = 1;
        while(i <= size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            int largest = i;
            
            if(leftIndex <= size && arr[leftIndex] > arr[largest]){
                largest = leftIndex;
            }
            if(rightIndex <= size && arr[rightIndex] > arr[largest]){
                largest = rightIndex;
            }
            
            if(largest != i){
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else{
                return;
            }
        }
    }
};

int main(){
    heap h; 
    h.maxHeap(50);
    h.maxHeap(55);
    h.maxHeap(53);
    h.maxHeap(54);
    h.maxHeap(52);
    
    h.print();
    h.deleteFromHeap();
    h.print();
    
    return 0;
}