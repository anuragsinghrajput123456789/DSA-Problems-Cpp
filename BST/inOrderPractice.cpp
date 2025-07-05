#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(node* root, vector<int> &ans){
    //base case
    if(root == NULL) return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

// This function is not used for predecessor/successor logic but is syntactically correct.
void preOrder(node* root){
    //base case
    if(root == NULL) return;

    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}


vector<int> mergeArray(vector<int>a,vector<int>b){
  //merge kardo bhai isme to bas
  
  vector<int>ans = (a.size() + b.size());
  
  int i=0,j=0,k=0;
  while(i < a.size() && j < b.size()){
    if(a[i] < b[j]){
     ans[k++] = a[i]; 
      i++;
    }
    else{
      ans[k++] = b[j];
      j++;
    }
  }
  
  while(i < a.size()){
    ans[k++] = a[i++]; 
  }
  
  while(j < b.size()){
    ans[k++] = b[j++];
  }
  
}

node* mergeBst(node* root1,node* root2){
   //step 1 : store inOrder
   vector<int>bst1,bst2;
   inOrder(root1,bst1);
   inOrder(root2,bst2);
   
   vector<int> mergeArray = mergeArray()
}


node* inOrderToBst(int s,int e,vector<int> &ans){
  //base case
  if(s > e)return null; 

  int mid = e + (s - e)/2; 
  node* root = new node(ans[mid]);
  root->left = inOrderToBst(s,mid-1,ans);
  root->right inOrderToBst(mid,e,ans);
  return root; 
}


// Function to find predecessor and successor of a given key in a BST.
// It uses an in-order traversal to get a sorted list of elements.
pair<int,int> preseccorSuccessor(node* root, int key){
    // Initialize predecessor and successor. -1 indicates not found.
    pair<int,int> ans = {-1, -1};

    // Vector to store the in-order traversal of the BST.
    vector<int> v1;
    inOrder(root, v1); // Populate the vector with sorted elements.

    int n = v1.size(); // Get the total number of elements.

    // Iterate through the sorted vector to find the key.
    for(int i = 0; i < n; i++){
        if(v1[i] == key){ // If the current element matches the key.
            // Check if a predecessor exists (i.e., not the first element).
            if(i > 0){
                ans.first = v1[i-1]; // The element before is the predecessor.
            }
            // Check if a successor exists (i.e., not the last element).
            if(i < n - 1){
                ans.second = v1[i+1]; // The element after is the successor.
            }
            break; // Once the key is found, we can stop searching.
        }
    }
    return ans; // Return the pair of predecessor and successor.
}

int main(){
    // Constructing the Binary Search Tree
    // The tree structure is:
    //         44
    //        /  \
    //       22   55
    //      /  \
    //     11   33
    node* p1 = new node(44);
    node* p2 = new node(22);
    node* p3 = new node(55);
    node* p4 = new node(11);
    node* p5 = new node(33);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    pair<int,int> finalAns;

    // Example usage: Find predecessor and successor for key 44
    // (Predecessor: 33, Successor: 55)
    finalAns = preseccorSuccessor(p1, 44);

    // Output the results
    cout << "Predecessor of 44 is: " << finalAns.first << endl;
    cout << "Successor of 44 is: " << finalAns.second << endl;

    cout << "---" << endl;

    // Example usage: Find predecessor and successor for key 11 (smallest element)
    // (Predecessor: -1, Successor: 22)
    finalAns = preseccorSuccessor(p1, 11);
    cout << "Predecessor of 11 is: " << finalAns.first << endl;
    cout << "Successor of 11 is: " << finalAns.second << endl;

    cout << "---" << endl;

    // Example usage: Find predecessor and successor for key 55 (largest element)
    // (Predecessor: 44, Successor: -1)
    finalAns = preseccorSuccessor(p1, 55);
    cout << "Predecessor of 55 is: " << finalAns.first << endl;
    cout << "Successor of 55 is: " << finalAns.second << endl;

    // Free allocated memory to prevent memory leaks
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}