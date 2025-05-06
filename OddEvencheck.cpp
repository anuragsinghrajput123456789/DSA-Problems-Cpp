//ODD EVEN CHECK THORUGH BITS
#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n; 
	cin >> n; 
	if(n & 1){
        cout << "Odd"; 
	}
	else{
		cout << "Even"; 
	}
	return 0; 
}
