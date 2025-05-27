#include <bits/stdc++.h> 

using namespace std; 
void printPattern(int n) {
	// Write your code here.
	for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout << " ";
		}
		for(int j=0; j<2*i+1; j++){
           cout << "*"; 
		}

       cout << endl; 
	}
}

int main(){


    return 0; 
}