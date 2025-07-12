#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        // row, col, step(distance)
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[r][c] = steps;
            
            for(int i = 0 ; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, steps + 1});
                    vis[nrow][ncol] = 2;
                  
                }
            }
            
        }
        return dist;
    }
    
};