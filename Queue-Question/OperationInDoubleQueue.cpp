#include <bits/stdc++.h>
using namespace std;

class Deque {
    vector<int> arr;
    int front, rear, size, capacity;

public:
    // Initialize your data structure.
    Deque(int n) {
        arr.resize(n);
        capacity = n;
        size = 0;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool pushFront(int x) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = x;
        size++;
        return true;
    }

    bool pushRear(int x) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = x;
        size++;
        return true;
    }

    int popFront() {
        if (isEmpty()) return -1;

        int val = arr[front];
        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return val;
    }

    int popRear() {
        if (isEmpty()) return -1;

        int val = arr[rear];
        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};


int main(){


    return 0; 
}