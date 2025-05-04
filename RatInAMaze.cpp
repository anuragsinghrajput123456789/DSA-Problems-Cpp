#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        return (x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0 && m[x][y] == 1);
    }
    
    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // If we've reached the destination
        if(x == n - 1 && y == n - 1) {
            ans.push_back(path); 
            return;
        }
        
        // Mark the current cell as visited
        visited[x][y] = 1; 
        
        // Directions: Down, Left, Right, Up
        // Down
        if(isSafe(x + 1, y, n, visited, m)) {
            path.push_back('D');
            solve(m, n, ans, x + 1, y, visited, path);
            path.pop_back();
        }
        
        // Left
        if(isSafe(x, y - 1, n, visited, m)) {
            path.push_back('L');
            solve(m, n, ans, x, y - 1, visited, path);
            path.pop_back();
        }
        
        // Right
        if(isSafe(x, y + 1, n, visited, m)) {
            path.push_back('R');
            solve(m, n, ans, x, y + 1, visited, path);
            path.pop_back();
        }

        // Up
        if(isSafe(x - 1, y, n, visited, m)) {
            path.push_back('U');
            solve(m, n, ans, x - 1, y, visited, path);
            path.pop_back();
        }
        
        // Backtrack: Unmark the current cell
        visited[x][y] = 0; 
    }
    
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans; 
        int n = maze.size(); // Assuming square grid (n x n)
        
        // If the starting cell is blocked, no solution
        if(maze[0][0] == 0) {
            return ans; 
        }
        
        // Initialize visited matrix
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        string path = ""; 
        solve(maze, n, ans, 0, 0, visited, path);
        
        // Sort the paths lexicographically
        sort(ans.begin(), ans.end());
        
        return ans; 
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        vector<string> result = obj.ratInMaze(mat);

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
