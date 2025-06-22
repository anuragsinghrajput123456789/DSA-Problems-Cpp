#include <iostream>
#include <string>
using namespace std;

void solve(string input, int index){
	// base case
	if(index >= input.length()){
		cout<<input<<endl;
		return ;
	}

	for(int i=index;i<input.length();i++){
		swap(input[index],input[i]);
		solve(input, index+1);
		// backtrack
		swap(input[index],input[i]);
	}
}

void printPermutations(string input){
	int index = 0;
	solve(input, index);
}

int main(){


    return 0; 
}