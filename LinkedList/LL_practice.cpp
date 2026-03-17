#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    // distructor is there...
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;`
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};

void printLL(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtPosition(node *&head, int position, int data)
{
    node *temp = head;
    int cnt = 0;
    node *nodeToinsert = new node(data);
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteNodeByPosition(int position, node *&head)
{

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    node *curr = head;
    node *prev = nullptr;

    int cnt = 1;
    while (cnt < position)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}

void deleteNodeByValue(node *&head, int data)
{

    if (head == nullptr)
        return;

    // if head node matches
    if (head->data == data)
    {
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    node *curr = head;
    node *prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->data == data)
        {
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{

    node *head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    printLL(head);

    insertAtPosition(head, 2, 15);
    printLL(head);

    deleteNodeByPosition(3, head);
    printLL(head);

    deleteNodeByValue(head, 20);
    printLL(head);

    return 0;
}