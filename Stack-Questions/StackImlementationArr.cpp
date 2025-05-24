// STACK  IMPLEMENTATION USING ARRAYS



#include <iostream>
using namespace std;

class MyStack {
private:
    int size;
    int top;
    int *arr;

public:
    MyStack(int s) : size(s), top(-1), arr(new int[s]) {
      
    }
    ~MyStack() { delete[] arr; }

    void push(int data) {
        if (top >= size - 1) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++top] = data;
        }
    }

    void print() const {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyStack st(50);

    st.push(10);
    st.push(20);
    st.push(30);

    st.print();

    return 0;
}
