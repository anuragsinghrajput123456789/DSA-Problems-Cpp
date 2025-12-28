#include<bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insertIntoHeap(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void printHeap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() {
        if (size == 0) return;

        // Step 1: Put last element into first index
        arr[1] = arr[size];

        // Step 2: Remove last element
        size--;

        // Step 3: Take root node to its correct position
        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i; // Assume root is largest initially

            // Check if left child exists and is greater than current largest
            if (leftIndex <= size && arr[leftIndex] > arr[largest]) {
                largest = leftIndex;
            }
            // Check if right child exists and is greater than current largest
            if (rightIndex <= size && arr[rightIndex] > arr[largest]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest; // Move down to the child's position
            } else {
                return; // Logic Correct: Parent is bigger than both children
            }
        }
    }
};

// Standalone Heapify Function
// n = size of the heap
// i = index to heapify
void heapifyAlgo(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i;
    int right = 2 * i + 1;

    // If left child is larger than root
    if (left <= n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapifyAlgo(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    
    while (size > 1) {
        // Step 1: Swap root (largest) with last element
        swap(arr[size], arr[1]);
        size--;

        // Step 2: Heapify root element to correct position
        heapifyAlgo(arr, size, 1);
    }
}

int main() {

    // --- Part 1: Testing Class Heap ---
    cout << "--- Testing Heap Class ---" << endl;
    heap h;
    h.insertIntoHeap(50);
    h.insertIntoHeap(55);
    h.insertIntoHeap(53);
    h.insertIntoHeap(52);
    h.insertIntoHeap(54);
    
    cout << "Heap after insertion: ";
    h.printHeap();

    h.deleteFromHeap();
    cout << "Heap after deletion:  ";
    h.printHeap();
    cout << endl;

    // --- Part 2: Testing Heapify and Sort ---
    cout << "--- Testing Heapify & HeapSort ---" << endl;
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5; // Actual number of elements (indices 1 to 5)

    // Build Heap
    for (int i = n / 2; i > 0; i--) {
        heapifyAlgo(arr, n, i);
    }

    cout << "Array after building heap: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap Sort
    heapSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}