#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int f(vector<int>& arr, int i, int j) {
        
        // base case
        if(i == j) return 0;
        
        int mini = INT_MAX;
        
        for(int k = i; k < j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + 
            f(arr, i, k) + f(arr, k+1, j);
            
            mini = min(mini, steps);
        }
        
        return mini;
    }
    int f_mem(vector<vector<int>>& dp, vector<int>& arr, int i, int j) {
        
        // base case
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int k = i; k < j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + 
            f_mem(dp, arr, i, k) + f_mem(dp, arr, k+1, j);
            
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }
    int f_tab(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        
        for(int i = n-1; i >= 1; i--) {
            for(int j = i+1; j <= n-1; j++) {
                int mini = INT_MAX;
        
                for(int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] + 
                    dp[i][k] + dp[k+1][j];
                    
                    mini = min(mini, steps);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        // return f(arr, 1, n-1);
        
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f_mem(dp, arr, 1, n-1);
        
        return f_tab(arr);
    }
};