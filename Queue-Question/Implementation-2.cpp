#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Insert at rear
    void pushRear(int data) {
        if ((rear + 1) % size == front) {
            cout << "Deque overflow from rear" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
    }

    // Insert at front
    void pushFront(int data) {
        if ((rear + 1) % size == front) {
            cout << "Deque overflow from front" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }

        arr[front] = data;
    }

    // Delete from front
    int popFront() {
        if (front == -1) {
            cout << "Deque underflow from front" << endl;
            return -1;
        }

        int data = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return data;
    }

    // Delete from rear
    int popRear() {
        if (rear == -1) {
            cout << "Deque underflow from rear" << endl;
            return -1;
        }

        int data = arr[rear];

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }

        return data;
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.display();

    cout << "Popped from front: " << dq.popFront() << endl;
    dq.display();

    cout << "Popped from rear: " << dq.popRear() << endl;
    dq.display();

    dq.pushFront(15);
    dq.pushRear(25);
    dq.display();

    return 0;
}
