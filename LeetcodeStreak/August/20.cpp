#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int r, int c, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if(r<0 || r>=m || c < 0 || c>=n || matrix[r][c] == 0) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int up = f(r-1,c,m,n,dp,matrix);
        int left = f(r,c-1,m,n,dp,matrix);
        int dia = f(r-1,c-1,m,n,dp,matrix);

        return dp[r][c] = 1 + min({up, left, dia});
    }
    int solveTab(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0;i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) dp[i][j] = 1;
                    else{
                        int up = dp[i-1][j];
                        int left = dp[i][j-1];
                        int dia = dp[i-1][j-1];

                        dp[i][j] = 1 + min({up, left, dia});
                    }
                }
                ans += dp[i][j];
            }
        }

        return ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // int n = matrix[0].size();
        // int ans = 0;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // for(int i = 0;i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         ans += f(i, j, m, n, dp,matrix);
        //     }
        // }

        // return ans;

        return solveTab(matrix);
    }
};