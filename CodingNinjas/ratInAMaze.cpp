#include <bits/stdc++.h>
using namespace std;

void findPath(int r, int c, vector<vector<int>>& mat, string path, vector<string>& res) {
    int n = mat.size();
    // Boundary check, obstacle check, or visited check
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0) return;

    // Destination reached
    if (r == n - 1 && c == n - 1) {
        res.push_back(path);
        return;
    }

    mat[r][c] = 0; // Mark as visited
    
    // Explore: Down, Left, Right, Up (Lexicographical order: D-L-R-U)
    findPath(r + 1, c, mat, path + 'D', res);
    findPath(r, c - 1, mat, path + 'L', res);
    findPath(r, c + 1, mat, path + 'R', res);
    findPath(r - 1, c, mat, path + 'U', res);
    
    mat[r][c] = 1; // Backtrack: Unmark
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> result;
    if (arr[0][0] != 0) findPath(0, 0, arr, "", result);
    return result;
}

int main(){

    


    return 0;
}