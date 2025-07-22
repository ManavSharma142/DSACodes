#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int f(int index, vector<int>& coins, int n, int sum) {
        
        // base cases
        if(sum < 0) return 0;
        
        if(sum == 0)return 1;
        int ans = 0;
        
        for(int i = index; i < n; i++) {
            ans += f(i, coins, n, sum-coins[i]);
        }
        
        return ans;
        
    }
    int f_mem(vector<vector<int>>& dp, int index, vector<int>& coins, int n, int sum) {
        
        // base cases
        if(sum < 0) return 0;
        
        if(sum == 0)return 1;
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int ans = 0;
        for(int i = index; i < n; i++) {
            ans += f_mem(dp, i, coins, n, sum-coins[i]);
        }
        
        return dp[index][sum] = ans;
    }
    int f_tab(vector<int>& coins, int n, int sum1) {
        
        vector<vector<int>> dp(n+1, vector<int> (sum1+1, 0));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for(int index = n; index >= 0; index--) {
            for(int sum = 1; sum <= sum1; sum++) {
                int ans = 0;
                for(int i = index; i < n; i++) {
                    if(sum - coins[i] >= 0)
                        ans += dp[i][sum-coins[i]];
                }
                dp[index][sum] = ans;
                    
            }
        }
        
        return dp[0][sum1];
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        
        int n = coins.size();
        // int index = 0;
        // return f(index,coins, n, sum);

        
        // vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        // return f_mem(dp, index, coins , n,sum);
        
        return f_tab(coins, n, sum);
    }
};