#include<bits/stdc++.h>
using namespace std; 

int celebrityBruteForce(vector<vector<int>>& mat) {
    int n = mat.size();

    for(int i = 0; i < n; i++) {
        bool rowCheck = true;
        bool colCheck = true;

        // Row check
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                rowCheck = false;
                break;
            }
        }

        // Column check
        for(int j = 0; j < n; j++) {
            if(i != j && mat[j][i] == 0) {
                colCheck = false;
                break;
            }
        }

        if(rowCheck && colCheck) return i;
    }

    return -1;
}

int celebrityTwoPointer(vector<vector<int>>& mat) {
    int n = mat.size();
    
    int a = 0, b = n - 1;

    // Step 1: Find candidate
    while(a < b) {
        if(mat[a][b] == 1) {
            a++;   // a knows b → remove a
        } else {
            b--;   // a doesn't know b → remove b
        }
    }

    int candidate = a;

    // Step 2: Verify

    // Row check
    for(int i = 0; i < n; i++) {
        if(mat[candidate][i] == 1) return -1;
    }

    // Column check
    for(int i = 0; i < n; i++) {
        if(i != candidate && mat[i][candidate] == 0) return -1;
    }

    return candidate;
}

int celebrityStack(vector<vector<int>>& mat) {
    int n = mat.size();

    int candidate = 0;

    // Step 1: Find candidate
    for(int i = 1; i < n; i++) {
        if(mat[candidate][i] == 1) {
            candidate = i;
        }
    }

    // Step 2: Verify
    for(int i = 0; i < n; i++) {
        if(i != candidate) {
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    }

    return candidate;
}


int main(){
  
  return 0; 
}
