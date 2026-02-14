#include<bits/stdc++.h>
using namespace std;

int main(){

    // ---------- VECTOR ----------
    vector<int> v = {5,1,3,10,7};

    v.push_back(20);
    v.pop_back();

    sort(v.begin(), v.end()); // ascending

    cout<<"Vector: ";
    for(int x : v) cout<<x<<" ";
    cout<<endl;

    cout << " Binary search 3 : "<<binary_search(v.begin(), v.end(), 3)<<endl;



    // ---------- DEQUE ----------
    deque<int> dq;

    dq.push_front(2);
    dq.push_back(4);
    dq.push_front(1);

    cout << "Deque front: " << dq.front() << endl;
    cout << "Deque back: " << dq.back() << endl;



    // ---------- LIST (doubly linked) ----------
    list<int> l = {2,4,6};

    l.push_front(1);
    l.push_back(8);

    cout<<"List: ";
    for(int x:l) cout<<x<<" ";
    cout<<endl;



    // ---------- STACK ----------
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"Stack top: "<<st.top()<<endl;
    st.pop();



    // ---------- QUEUE ----------
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);

    cout<<"Queue front: "<<q.front()<<endl;
    q.pop();



    // ---------- PRIORITY QUEUE ----------
    priority_queue<int> maxHeap; // largest first
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);

    cout<<"MaxHeap top: "<<maxHeap.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(30);

    cout<<"MinHeap top: "<<minHeap.top()<<endl;



    // ---------- SET ----------
     set<int> s = {4,1,7,1,4}; 
    // duplicates removed

    s.insert(9);

    cout<<"Set: ";
    for(int x:s) cout<<x<<" ";
    cout<<endl;



    // ---------- MAP ----------
    map<int,string> m;

    m[1] = "Anurag";
    m[2] = "Rahul";

    cout<<"Map value key 1: "<<m[1]<<endl;



    // ---------- UNORDERED MAP ----------
    unordered_map<string,int> um;

    um["apple"] = 3;
    um["banana"] = 5;

    cout<<"Unordered map banana: "<<um["banana"]<<endl;



    // ---------- PAIR ----------
    pair<int,string> p = {101,"Code"};

    cout<<"Pair: "<<p.first<<" "<<p.second<<endl;



    // ---------- ALGORITHMS ----------
    vector<int> a = {9,2,5,2,7};

    cout<<"Count of 2: "<<count(a.begin(), a.end(), 2)<<endl;

    reverse(a.begin(), a.end());

    cout<<"Reversed: ";
    for(int x:a) cout<<x<<" ";
    cout<<endl;

    auto it = find(a.begin(), a.end(), 5);
    if(it != a.end()) cout<<"5 found"<<endl;



    // ---------- LAMBDA ----------
    sort(a.begin(), a.end(), [](int x, int y){
        return x > y; // descending
    });

    cout<<"Sorted desc: ";
    for(int x:a) cout<<x<<" ";
    cout<<endl;



    // ---------- ITERATOR ----------
    vector<int>::iterator itr;

    cout<<"Using iterator: ";
    for(itr = v.begin(); itr!=v.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;



    return 0;
}