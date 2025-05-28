//Function to push an element into the queue.
#include<bits/stdc++.h>

void MyQueue:: push(int x)
{
        if(front == NULL)
        {
            QueueNode *newNode = new QueueNode(x); // creating the node
            front = newNode;
            rear = newNode;
        }
        else
        {
             QueueNode *newNode = new QueueNode(x);
             rear -> next = newNode;
             rear = newNode;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        if(front == nullptr)
        {
            return -1;
        }
        else
        {
           QueueNode *ptr = front;
           front = front->next;
           int elem = ptr->data;
           delete ptr;
           return elem;
        }
}

int main(){



    return 0;
}