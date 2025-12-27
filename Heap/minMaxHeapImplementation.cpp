#include<bits/stdc++.h>
using namespace std;

class heap{
public:
    int size;
    int arr[100];

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insertIntoMaxHeap(int val){
        size++;
        int i = size;
        arr[i] = val;

        while(i > 1){
            int parent = i / 2;
            if(arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }else break;
        }
    }

    void insertIntoMinHeap(int val){
        size++;
        int i = size;
        arr[i] = val;

        while(i > 1){
            int parent = i / 2;
            if(arr[parent] > arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }else break;
        }
    }

    void printHeap(){
        for(int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// -------- Correct Heapify --------
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[largest])
        largest = left;

    if(right <= n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


int main(){
    heap h;

    h.insertIntoMinHeap(11);
    h.insertIntoMinHeap(22);
    h.insertIntoMinHeap(55);
    h.insertIntoMinHeap(54);
    h.insertIntoMinHeap(31);

    h.printHeap();

    int arr[] = {-1,54,53,55,52,50}; 
    int n = 5; // valid heap size (ignore index 0)

    for(int i = n/2; i >= 1; i--)
        heapify(arr, n, i);

    cout << "Printing Max Heap array:\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
