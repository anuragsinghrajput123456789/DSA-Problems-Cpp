// MIDDLE NODE OF THE LINEKD LIST IS HERE...

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Initial template for C++

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; 
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    
    int getMiddle(Node* head) {
         Node* slow = head;
       Node* fast = head;
       if(head==NULL){
            return -1;
        }
        if(head->next==NULL){
            return head->data;
        }
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next; //1 time 
            fast=fast->next->next; //2 time
        }
        return slow->data;

    }
    };



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        cout << ob.getMiddle(head) << endl;
        cout << "~" << endl;
    }

    return 0;
}

int main(){



    return 0; 
}