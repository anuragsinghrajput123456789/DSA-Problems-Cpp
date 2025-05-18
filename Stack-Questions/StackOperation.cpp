
#include <bits/stdc++.h>
using namespace std;


class Geeks {
  public:
    // Function to insert element to stack
     void insert(stack<int>& st, int x) {
        
        st.push(x);
        return;
        // Your code here
    }

    // Function to pop element from stack
    void remove(stack<int>& st) {
        if(st.empty()){return;}
        st.pop();
        return;
        // Your code here
    }

    void headOf_Stack(stack<int>& st) {
        cout<<st.top()<<endl;
        return;
        // Print top of stack
    }

    // Function to find the element in stack, print Yes,if found, else print No.
    void find(stack<int>& st, int val) {
        stack<int> temp;
       bool found=false;
       while(!st.empty()){
           if(st.top()==val){
               found=true;
           }
           temp.push(st.top());
           st.pop();
       }
       while(!temp.empty()){
           st.push(temp.top());
           temp.pop();
       }
       if(found){
           cout<<"Yes"<<endl;
       }
       else{
           cout<<"No"<<endl;
       }
        
        // Your code here
    }

};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        // Declaring stack of integers
        stack<int> st;

        int q;
        cin >> q;

        // Working with queries
        while (q--) {
            char ch;
            cin >> ch;
            Geeks obj;
            if (ch == 'i') {
                int x;
                cin >> x;
                obj.insert(st, x);
            }

            if (ch == 'r') {
                obj.remove(st);
            }

            if (ch == 'h') {
                obj.headOf_Stack(st);
            }
            if (ch == 'f') {
                int x;
                cin >> x;
                obj.find(st, x);
            }
        }
    }
}

int main(){


    return 0; 
}