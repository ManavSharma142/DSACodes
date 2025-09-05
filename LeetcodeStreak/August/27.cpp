#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int dp[501][501][2][2][5];
    int solve(int row, int col, bool turned, bool expect_two, int dir, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return 0;
        int expected_val = expect_two ? 2 : 0;
        if (grid[row][col] != expected_val) return 0;
        if(dp[row][col][turned][expect_two][dir] != -1) return dp[row][col][turned][expect_two][dir];

        int ans = 0;
        if (dir == 1) {
            ans = 1 + solve(row + 1, col + 1, turned, !expect_two, 1, grid);

            if (!turned) {
                ans = max(ans, 1 + solve(row + 1, col - 1, true, !expect_two, 3, grid));
            }
        }
        if (dir == 2) {
            ans = 1 + solve(row - 1, col + 1, turned, !expect_two, 2, grid);
            if (!turned) {
                ans = max(ans, 1 + solve(row + 1, col + 1, true, !expect_two, 1, grid));
            }
        }
        if (dir == 3) {
            ans = 1 + solve(row + 1, col - 1, turned, !expect_two, 3, grid);
            if (!turned) {
                ans = max(ans, 1 + solve(row - 1, col - 1, true, !expect_two, 4, grid));
            }
        }
        if (dir == 4) {
            ans = 1 + solve(row - 1, col - 1, turned, !expect_two, 4, grid);
            if (!turned) {
                ans = max(ans, 1 + solve(row - 1, col + 1, true, !expect_two, 2, grid));
            }
        }
        return dp[row][col][turned][expect_two][dir] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find a '1', it's a potential start of a segment.
                if (grid[i][j] == 1) { // <-- TYPO FIX
                    ans = max(ans, 1); // A single '1' is a valid segment of length 1.
                    ans = max(ans, 1 + solve(i + 1, j + 1, false, true, 1, grid));
                    ans = max(ans, 1 + solve(i - 1, j + 1, false, true, 2, grid));
                    ans = max(ans, 1 + solve(i + 1, j - 1, false, true, 3, grid));
                    ans = max(ans, 1 + solve(i - 1, j - 1, false, true, 4, grid));
                }
            }
        }
        return ans;
    }
};