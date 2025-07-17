// DFS Appraoch : TLE, not optimal, do bfs, as bfs is level by level
class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<int>>& vis, int n) {
        
        if( x >= 1 && y >= 1 && x <= n && y <= n && vis[x][y] != 1) return true;
        else return false;
    }
    void solve(int Steps, int n, int& minStep, int x, int y, int destX, int destY, vector<vector<int>>& vis) {
        
        if(Steps >= minStep) return ;
        if(x == destX && y == destY) {
            minStep = min(minStep, Steps);
            return ;
        }
        
        vis[x][y] = 1;
        
        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {-1, 1 ,2, -2, 2, -2, 1, -1};
        
        for(int i = 0; i < 8; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(isSafe(newx, newy, vis, n)) 
                solve(Steps+1, n, minStep, newx, newy, destX, destY, vis);
        }
        
        vis[x][y] = 0;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int minStep = INT_MAX;
        
        if(knightPos == targetPos) return 0;
        
        int destX = targetPos[0];
        int destY = targetPos[1];
        
        int srcx = knightPos[0];
        int srcy = knightPos[1];
        
        vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
        
        solve(0, n, minStep, srcx, srcy, destX, destY, vis);
        
        return minStep;
    }
};


// BFS (optimised approach)
class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<int>>& vis, int n) {
        
        if( x >= 1 && y >= 1 && x <= n && y <= n && vis[x][y] != 1) return true;
        else return false;
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {

        if(knightPos == targetPos) return 0;
        
        // DS :
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n+1, vector<int> (n+1, 0));
        
        q.push({{knightPos[0], knightPos[1]}, 0});
        vis[knightPos[0]][knightPos[1]] = 1;

        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {-1, 1 ,2, -2, 2, -2, 1, -1};
        
        while(!q.empty()) {
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            
            int x = front.first.first;
            int y = front.first.second;
            int steps = front.second;
            
            if(x == targetPos[0] && y == targetPos[1]) return steps;
            
            for (int i = 0; i < 8; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (isSafe(newx, newy, vis, n)) {
                    vis[newx][newy] = 1;
                    q.push({{newx, newy}, steps + 1});
                }
            }
        }
        
        return -1;
        
    }
};