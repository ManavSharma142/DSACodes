#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long
    int solve(vector<vector<int>>& fruits, int row, int col, int moves, vector<vector<int>>& dp, vector<pair<int, int>>& dirs) {
        int n = fruits.size();
        if(row == n-1 && col == n-1) {
            return moves == 0 ? 0 : INT_MAX;
        }
        if(moves == 0 || row == col) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        ll maxFruits = -1;
        for(auto [dRow, dCol] : dirs) {
            int newR = row + dRow;
            int newC = col + dCol;
            if(newR >= 0 && newR < n && newC < n && newC >= 0) {
                int val = solve(fruits, newR, newC, moves-1, dp, dirs);
                if(val != INT_MAX) maxFruits = max(maxFruits, (ll)val);
            }
        }

        return dp[row][col] = (maxFruits < 0 ? INT_MAX : fruits[row][col] + maxFruits);
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        ll child1 = 0;
        for(int i = 0 ;i < n; i++) {
            child1 += fruits[i][i];
            fruits[i][i] = 0;
        }

        vector<pair<int, int>> downDirs = {{1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int child2 = solve(fruits, 0, n-1, n-1, dp, downDirs);

        vector<pair<int, int>> rightDirs = {{-1, 1}, {0, 1}, {1, 1}};
        for(auto& row : dp) fill(row.begin(), row.end(), -1);
        int child3 = solve(fruits, n-1, 0, n-1, dp, rightDirs);

        return child1 + child2 + child3; 
    }
};