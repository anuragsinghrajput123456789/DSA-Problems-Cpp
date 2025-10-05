// DLL INSERTION DELETION (Corrected)

#include<iostream> // Use iostream for standard I/O
using namespace std;

class node{
  public:
  int data; 
  node* prev;
  node* next; 
  
  // Constructor
  node(int data){
    this->data = data;
    this->next = NULL; 
    this->prev = NULL;
  }
};

// --- Utility Functions ---

void printLL(node* head){
  node* temp = head;
  if (temp == NULL) {
    cout << "List is empty!" << endl;
    return;
  }
  cout << "List: ";
  while(temp != NULL){
    cout << temp->data << " <-> "; 
    temp = temp->next; 
  }
  cout << "NULL" << endl;
}

int getLength(node* head){
  int ans = 0; 
  node* temp = head; 
  while(temp != NULL){
    ans++;
    temp = temp->next; 
  }
  return ans; 
}

// --- Insertion Functions ---

void insertAtHead(node* &head, node* &tail, int data){
  // Handle empty list case
  if(head == NULL){
    node* temp = new node(data);
    head = temp;
    tail = temp;
  } else {
    node* temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void insertAtTail(node* &head, node* &tail, int data){
  // Handle empty list case
  if(tail == NULL){
    node* temp = new node(data);
    head = temp;
    tail = temp;
  } else {
    node* temp = new node(data);
    tail->next = temp; 
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtPosition(node* &head, node* &tail, int data, int position){
  // 1. Insert at start (position 1)
  if(position == 1){
    insertAtHead(head, tail, data);
    return;
  }
  
  node* temp = head;
  int cnt = 1;
  
  // 2. Traverse to the node *before* the desired position
  while(cnt < position - 1 && temp != NULL){
    temp = temp->next; 
    cnt++;
  }

  // If position is out of bounds (e.g., trying to insert at pos 10 in a list of 5)
  if (temp == NULL) {
      cout << "Invalid position." << endl;
      return;
  }
  
  // 3. Insert at the end
  if(temp->next == NULL){
    insertAtTail(head, tail, data);
    return;
  }
  
  // 4. Insert in the middle
  node* nodeToInsert = new node(data);
  nodeToInsert->next = temp->next;
  temp->next->prev = nodeToInsert;
  temp->next = nodeToInsert;
  nodeToInsert->prev = temp;
}

int main(){
  
  node* head = NULL; 
  node* tail = NULL;

  insertAtHead(head, tail, 11); // List: 11
  insertAtHead(head, tail, 22); // List: 22 <-> 11
  insertAtHead(head, tail, 33); // List: 33 <-> 22 <-> 11
  insertAtHead(head, tail, 44); // List: 44 <-> 33 <-> 22 <-> 11
  
  cout << "Initial list:" << endl;
  printLL(head);
  cout << "Length: " << getLength(head) << endl << endl;
  
  cout << "After inserting 25 at the tail:" << endl;
  insertAtTail(head, tail, 25); // List: 44 <-> 33 <-> 22 <-> 11 <-> 25
  printLL(head);
  cout << "Length: " << getLength(head) << endl << endl;
  
  cout << "After inserting 59 at position 3:" << endl;
  insertAtPosition(head, tail, 59, 3); // List: 44 <-> 33 <-> 59 <-> 22 <-> 11 <-> 25
  printLL(head);
  cout << endl;

  cout << "After inserting 99 at position 1 (head):" << endl;
  insertAtPosition(head, tail, 99, 1);
  printLL(head);
  cout << endl;

  cout << "After inserting 100 at position 8 (tail):" << endl;
  insertAtPosition(head, tail, 100, 8);
  printLL(head);
  cout << endl;

  return 0;
}