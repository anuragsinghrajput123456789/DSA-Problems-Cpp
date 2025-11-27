#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

int length(Node *head)
{
    int cnt = 0;
    Node *p1 = head;
    while (p1 != NULL)
    {
        p1 = p1->next;
        cnt++;
    }
    return cnt;
}

int main()
{

    return 0;
}