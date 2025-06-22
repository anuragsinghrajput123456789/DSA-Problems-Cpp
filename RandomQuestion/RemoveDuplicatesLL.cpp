/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

 
Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return head; // Empty list, nothing to do
    }

    Node* ptr = head;

    while (ptr != NULL && ptr->next != NULL) {
        Node* p = ptr->next;
        if (p->data == ptr->data) {
            // Duplicate found, remove p
            ptr->next = p->next;
            delete p;
        } else {
            // Move to the next node
            ptr = ptr->next;
        }
    }

    return head;
}

int main(){


    return 0; 
}