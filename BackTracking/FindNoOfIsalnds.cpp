#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(int n, int m, int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 'L';
    }

    void bfs(int n, int m, int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;
        
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            int X = front.first;
            int Y = front.second;
            
            for(int i = 0 ; i < 8; i++) {
                int newx = X + dx[i];
                int newy = Y + dy[i];
                
                if(isSafe(n, m, newx, newy, grid, vis)) {
                    q.push({newx, newy});
                    vis[newx][newy] = true;
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'L' && !vis[i][j]) {
                    bfs(n, m , i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
