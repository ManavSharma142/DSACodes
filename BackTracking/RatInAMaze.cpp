// backtracking approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(int x, int y, int n, vector<vector<int>>& vis, vector<vector<int>>& maze) {
        
        if(x >= 0 && x < n && y >= 0 && y < n && vis[x][y] != 1 && maze[x][y] == 1) return true;
        else return false;
    }
    void solve(vector<vector<int>>& maze, vector<string>& ans, string path, int x, int y, int n, vector<vector<int>>& vis) {
        
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        // check for D, L, R, U
        
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        string dpath = "DLRU";
        
        for(int i = 0 ; i < 4; i++) {
            
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(isSafe(newx, newy, n, vis, maze))
                solve(maze, ans, path + dpath[i], newx, newy, n, vis);
                
        }
        vis[x][y] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        
        vector<string> ans;
        if(maze[0][0] == 0) return ans;
        
        string path = "";
        vector<vector<int>> vis(n, vector<int> (n, 0));
        solve(maze, ans, path, 0, 0, n, vis);
        
        return ans;
        
    }
};

// Recusive approach 
