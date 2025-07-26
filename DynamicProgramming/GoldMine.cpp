// first problem i encountered where we make 2 columns in space optmised solution
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int f(vector<vector<int>>& mat, int row, int col, int m, int n) {
        
        // base case
        if(row >= m || row < 0 || col >= n || col < 0) return 0;
        
        int diaUpRight = f(mat, row-1, col+1, m, n);
        int right = f(mat, row, col+1, m, n);
        int diaDownLeft = f(mat, row+1, col+1, m, n);
        
        return mat[row][col] + max(diaUpRight, max(right, diaDownLeft));
    }
    int f_mem(vector<vector<int>>& dp, vector<vector<int>>& mat, int row, int col, int m, int n) {
        
        // base case
        if(row >= m || row < 0 || col >= n || col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int diaUpRight = f_mem(dp, mat, row-1, col+1, m, n);
        int right = f_mem(dp, mat, row, col+1, m, n);
        int diaDownLeft = f_mem(dp, mat, row+1, col+1, m, n);
        
        return dp[row][col] = mat[row][col] + max(diaUpRight, max(right, diaDownLeft));
    }
    
    int f_tab(vector<vector<int>>& mat, int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++) {
            dp[i][n-1] = mat[i][n-1];
        }
        
        for(int col = n-2; col >= 0; col--) {
            for(int row = 0 ; row < m; row++) {
                int right = dp[row][col+1];
                int rightUp = row > 0 ? dp[row-1][col+1] : 0;
                int rightDown = row < m-1 ? dp[row+1][col+1] : 0;
                
                dp[row][col] = mat[row][col] + max({right, rightUp, rightDown});
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < m; i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
    int f_SO(vector<vector<int>>& mat, int m, int n) {
    
        vector<int> curr(m, 0);
        vector<int> next(m, 0);
        
        for(int i = 0; i < m; i++) {
            next[i] = mat[i][n-1];
        }
        
        for(int col = n-2; col >= 0; col--) {
            for(int row = 0 ; row < m; row++) {
                int right = next[row];
                int rightUp = row > 0 ? next[row-1] : 0;
                int rightDown = row < m-1 ? next[row+1] : 0;
                
                curr[row] = mat[row][col] + max({right, rightUp, rightDown});
            }
            next = curr;
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < m; i++) {
            ans = max(ans, next[i]);
        }
        return ans;
    }
    
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        int ans = INT_MIN;
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // for(int i = 0; i < m; i++) {
        //     int temp = f_mem(dp, mat, i, 0, m, n);
        //     ans = max(ans, temp);
        // }
        // return ans;
        
        
        return f_SO(mat, m, n);
    }
};