#include<bits/stdc++.h>
using namespace std;
int findNode(Node *head, int n){

    // Write your code here.

    Node* temp = head;

    int ctr = 0;

    while(temp){

        if(temp->data == n){

            return ctr;

        }

        ctr++;

        temp = temp->next;

    }

    return  -1;

}

int main(){


    return 0; 
}