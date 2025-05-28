// Function to push an element x in a queue.
#include<bits/stdc++.h>
using namespace  std;   




void MyQueuepush(int x) {
    // Push only if we are within array limits
    if (rear < 100005) {
        arr[rear] = x;
        rear++;
    }
}

// Function to pop an element from queue and return that element.
int MyQueuepop () {
    if (front == rear) {
        // Queue is empty
        return -1;
    } else {
        int ans = arr[front];
        front++;
        return ans;
    }
}
int main(){


    return 0; 
}