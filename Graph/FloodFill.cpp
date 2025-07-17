class Solution {
public:

    bool isSafe(int x, int y, int ogColor, int row, int col, vector<vector<int>>& image, vector<vector<int>>& vis) {
        if(x >= 0 && x < row && y >= 0 && y < col && image[x][y] == ogColor && vis[x][y] == 0) return true;

        else return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();

        if(image[sr][sc] == color) return image;

        vector<vector<int>> ans = image;
        vector<vector<int>> vis(row, vector<int> (col, 0));
        queue<pair<int, int>> q;

        int ogColor = image[sr][sc];

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        // do bfs
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;

  
            // check neighbours 
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(isSafe(newx, newy, ogColor,row, col, image, vis)) {
                    vis[newx][newy] = 1;
                    // update ans
                    ans[newx][newy] = color;
                    // push in q
                    q.push({newx, newy});
                }
            }
        }
        return ans;
    }
};