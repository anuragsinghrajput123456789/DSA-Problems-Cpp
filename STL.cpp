#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{

    // VECTOR ARE THERE BHAI ********************

    // vector<int> arr;

    // arr.push_back(32);
    // cout << "sizeof -> " << arr.capacity() << endl;
    // arr.push_back(2);
    // cout << "sizeof -> " << arr.capacity() << endl;
    // arr.push_back(3);

    // cout << "sizeof -> " << arr.capacity() << endl;


    // cout << "front me hai -> " << arr.front() << endl;
    // cout << "back me hai --> " << arr.back() << endl;

//     vector<int>arr = {7,8,4,6,5,1,3,2};

//     for(auto i : arr){
//   cout << i << endl; 
//     }


//******************************DEQUE IS THERE IT IS ....... */

deque<int> d; 

 d.push_back(2); 
 d.push_front(1);

 cout << "print first element" << d.at(1) << endl; 


 //********************************STACK ARE THERE BHAI....********** */
//  stack<string> s ;
//    s.push("love");
//    s.push("babbar");
   
//    s.pop();
   
//    cout << "top element : " << s.top() << endl; 



// *********************************QUEUE
queue<string>q; 
   
   q.push("love");
   q.push("babbar"); 
   q.push("kumar");
   
   cout << "sizeof the stack :  " << q.size();
   
   

   priority_queue<int> maxi; 
    
   // priority_queue<int, vector<int>, greater<int> > mini ;
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    
     int n = maxi.size();
    
    for(int i=0; i<n; i++){
      cout << maxi.top() << " " ; 
      maxi.pop();
    }
     cout << endl; 
    
    cout << "khali hai kya bhai " << maxi.empty() << endl; 




    set<int> s; 
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(5);
    s.insert(3);

    // Print elements of the set
    for(auto i : s){
        cout << i << endl; 
    }

    // Erase the first element (1)
    s.erase(s.begin());

    // Erase the next element (3)
    set<int>::iterator it = s.begin();
    it++;  // Move the iterator to the next element
    s.erase(it);

    // Print elements after erasing
    for(auto i : s){
        cout <<  i << endl; 
    }

        // MAPS ARE THERE HERER.........................................

    map<int,string> m; 
    m[1] = "Anurag"; 
    m[2] = "singh"; 
    m[3] = "babbar"; 
    
    m.insert({5, "bheem"});
    
    for(auto i : m){
      cout << i.second <<endl; 
    }
    
   
    
    

    vector<int> v; 
   
    v.push_back(1); 
    v.push_back(2);
     v.push_back(3); 
    v.push_back(4);
    v.push_back(5); 
    v.push_back(6);


    //....................................ALGOES ARE THERE BABY.......
     
    cout << binary_search(v.begin(),v.end(),5) << endl; 
 
 
   //   cout << "lower bound --> " << lower_bound(v.begin(), v.end(), 6) - v.begin()<< endl; 
     
     
   //   int a = 32; 
   //   int b= 12; 
     
   //   cout << a << endl; 
   //   cout << b << endl; 
     
     
   //   swap(a,b);
   //   cout << a << endl; 
   //   cout << b << endl; 
     
     
     
   //   string nm = "anurag";
   // reverse(nm.begin(),nm.end());
   // cout << nm << endl; 
    
    
    rotate(v.begin(),v.begin()+1, v.end());
    for(auto i : v){
      cout << i << endl; 
    }
     
     v.sort(v.begin(),v.end());
     cout << "sorting started here...." << endl; 
     for(auto i : v){
       cout << i << endl; 
     }




   return 0;
}
