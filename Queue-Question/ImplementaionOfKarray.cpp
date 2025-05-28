// C++ program to implement k queues 
// in a single array (Naive Approach)
#include <bits/stdc++.h>
using namespace std;

class kQueues {
private:
    vector<int> arr;       
    int n, k;             
    vector<int> front;    
    vector<int> rear;      

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
    }
    
    // Function to check if queue 'qn' is empty
    bool isEmpty(int qn) {
        return (front[qn] == -1);
    }
    
    // Function to check if queue 'qn' is full
    bool isFull(int qn) {
        // Calculate the next position after rear
        int nextPos = (rear[qn] + 1) % (n/k);
        // Queue is full if next position is front
        return (nextPos == front[qn] % (n/k) && front[qn] != -1);
    }
    
    // Function to enqueue 'x' into queue 'qn'
    bool enqueue(int x, int qn) {
        
        // Check if queue is full
        if (isFull(qn))
            return false;
            
        // Calculate the base index for this queue
        int base = qn * (n/k);
        
        // For empty queue, set front index
        if (isEmpty(qn))
            front[qn] = base;
        
        // Update rear and add element
        rear[qn] = (rear[qn] == -1) ? 
            base : 
            base + (rear[qn] + 1 - base) % (n/k);
        arr[rear[qn]] = x;
        
        return true;
    }
    
    // Function to dequeue from queue 'qn'
    int dequeue(int qn) {
        
        // Check if queue is empty
        if (isEmpty(qn))
            return -1;
            
        // Get the base index for this queue
        int base = qn * (n/k);
        
        // Get the element to be dequeued
        int x = arr[front[qn]];
        
        // If this is the last element, reset front and rear
        if (front[qn] == rear[qn]) {
            front[qn] = -1;
            rear[qn] = -1;
        } else {
            
            // Move front to next position, 
            // considering wrap-around within segment
            front[qn] = base + (front[qn] + 1 - base) % (n/k);
        }
        
        return x;
    }
};

int main() {
    int n = 10, k = 3;
    kQueues queues(n, k);
    
    cout << queues.enqueue(10, 0) << " "; 
    cout << queues.enqueue(20, 1) << " "; 
    cout << queues.enqueue(30, 0) << " "; 
    cout << queues.enqueue(40, 2) << " "; 
    
    cout << queues.dequeue(0) << " ";     
    cout << queues.dequeue(1) << " ";     
    cout << queues.dequeue(2) << " ";     
    cout << queues.dequeue(0) << " ";     
    cout << queues.dequeue(0) << " ";     
    
    return 0;
}