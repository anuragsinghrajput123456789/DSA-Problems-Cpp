#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i = 0; i < k; i++) {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    while(true) {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        int r = temp->row;
        int c = temp->col;

        if(c + 1 < n) {
            int nextElement = a[r][c + 1];
            maxi = max(maxi, nextElement);
            minHeap.push(new node(nextElement, r, c + 1));
        } else {
            break;
        }
    }

    return end - start + 1;
}
