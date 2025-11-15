#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    int front;
    int rear;
    int size;
    int *arr;

    // constructor
    MyQueue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // enqueue
    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    // dequeue
    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        return x;
    }

    // size of queue
    int getSize() {
        return rear - front;
    }

    // front element
    int getFront() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    MyQueue q(10);

    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(33);
    q.enqueue(44);
    q.enqueue(55);
    q.enqueue(66);

    cout << "Size of queue: " << q.getSize() << endl;

    cout << "Popped: " << q.dequeue() << endl;

    cout << "Size after pop: " << q.getSize() << endl;

    return 0;
}
