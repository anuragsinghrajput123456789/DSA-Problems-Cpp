#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int f;
    int r;
    int size;
    int* arr;

    Queue(int size) {
        this->size = size;
        this->arr = new int[size];
        this->f = -1;
        this->r = -1;
    }

    // Check if queue is full
    bool isFull() {
        return r == size - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (f == -1 || f > r);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (f == -1) f = 0; // First element insertion
        arr[++r] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Dequeued: " << arr[f] << endl;
        f++;
    }

    // Peek front element
    int peek() {
        if (!isEmpty()) {
            return arr[f];
        } else {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This should show overflow

    q.display();

    return 0;
}
