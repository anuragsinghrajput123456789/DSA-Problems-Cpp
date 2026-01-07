#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    int size;
    int arr[101];

    heap() {
        size = 0;          // OK
        arr[0] = -1;       // OK, unused index
    }

    void insertIntoHeap(int val) {

        // ❌ WRONG (your code)
        // if(size == 0) return;
        // Mistake 1: first element will never be inserted

        size++;                    // ✔ size must increase first
        int index = size;          // ❌ WRONG ORDER in your code
                                   // Mistake 2: index was taken before size++

        arr[index] = val;          // ❌ MISSING in your code
                                   // Mistake 3: value was never stored

        while (index > 1) {
            int parent = index / 2;

            // ❌ WRONG (your code)
            // if(arr[parent], arr[index])
            // Mistake 4: comma operator used instead of comparison

            if (arr[parent] < arr[index]) {   // ✔ correct comparison
                swap(arr[parent], arr[index]);
                index = parent;               // ❌ MISSING in your code
                                               // Mistake 5: index not updated
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

        // ❌ WRONG (your code)
        // size--;
        // arr[1] = arr[size];
        // Mistake 6: size reduced before copying last element

        arr[1] = arr[size];     // ✔ copy last to root
        size--;                 // ✔ reduce size after copy

        // ❌ WRONG (your code)
        // int i = 0;
        // Mistake 7: heap index starts from 1

        int i = 1;              // ✔ correct root index

        while (i <= size) {

            // ❌ WRONG (your code)
            // leftIndex and rightIndex calculated only once
            // Mistake 8

            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            // ❌ WRONG (your code)
            // used < size instead of <= size
            // Mistake 9

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);

                // ❌ WRONG (your code)
                // leftIndex = i or rightIndex = i
                // Mistake 10: i was never updated

                i = largest;    // ✔ move down
            } else {
                return;
            }
        }
    }
};

void heapifyAlgo(int arr[], int size, int i) {

    // ❌ WRONG (your code)
    // if(size == 0) return;
    // Mistake 11: unnecessary condition

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // ❌ WRONG (your code)
    // used < size instead of <= size
    // Mistake 12

    if (left <= size && arr[left] > arr[largest])
        largest = left;

    if (right <= size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        // ❌ WRONG (your code)
        // largest = i;
        // Mistake 13: resets value incorrectly

        heapifyAlgo(arr, size, largest);   // ✔ correct recursive call
    }
}

int main() {

    heap h;

    h.insertIntoHeap(11);
    h.insertIntoHeap(43);
    h.insertIntoHeap(22);
    h.insertIntoHeap(44);
    h.insertIntoHeap(66);
    h.insertIntoHeap(77);

    h.printHeap();

    h.deleteFromHeap();
    h.printHeap();

    return 0;
}
