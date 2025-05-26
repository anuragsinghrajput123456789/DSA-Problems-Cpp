#include <bits/stdc++.h>
using namespace std;

void reverseQueueHelper(queue<int> &q) {
    if (q.empty()) return;

    // Step 1: Dequeue front element
    int front = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueueHelper(q);

    // Step 3: Enqueue the removed item at the end
    q.push(front);
}

queue<int> reverseQueue(queue<int> q) {
    reverseQueueHelper(q);
    return q;
}

int main(){


    return 0; 
}