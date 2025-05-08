
// PALINDROME CHECK OF A LINKED LIST.......
#include <bits/stdc++.h>

using namespace std;

 

bool isPalindrome(LinkedListNode<int>* head) {

    if (head == NULL || head->next == NULL) {

        return true;

    }

 

    LinkedListNode<int>* temp = head;

    vector<int> arr;

 

    while (temp != NULL) {

        arr.push_back(temp->data);

        temp = temp->next;

    }

 

    int n = arr.size();

    for (int i = 0; i < n / 2; i++) {

        if (arr[i] != arr[n - i - 1]) {

            return false;

        }

    }

 

    return true;

}

int main(){


    return 0; 
}