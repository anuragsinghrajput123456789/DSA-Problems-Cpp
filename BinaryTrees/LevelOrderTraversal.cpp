#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(node* head) {
    if (head == NULL) return;

    queue<node*> q;
    q.push(head);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void ReverselevelOrderTraversal(node* head) {
    stack<int>st; 
    if (head == NULL) return;

    queue<node*> q;
    q.push(head);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            st.push(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    while(!st.empty()){
      cout << st.top() << endl;
      st.pop();
    }
}

int main() {
    node* p1 = new node(11);
    node* p2 = new node(22);
    node* p3 = new node(33);
    node* p4 = new node(44);
    node* p5 = new node(55);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    levelOrderTraversal(p1);
    cout << endl; 
    ReverselevelOrderTraversal(p1);

    return 0;
}
