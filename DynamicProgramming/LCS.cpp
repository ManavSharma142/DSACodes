#include<bits/stdc++.h>
using namespace std;
//Longest Common Subsequence (LCS) Problem
class Solution {
  public:
    int f(string& s1, int i, string& s2, int j) {
        // base case
        if(i < 0 || j < 0) return 0;
        
        if(s1[i] == s2[j]) return 1 + f(s1, i-1, s2, j-1);
        else return max(f(s1, i-1, s2, j) , f(s1, i, s2, j-1));
    }
    int f_mem(vector<vector<int>>& dp, string& s1, int i, string& s2, int j) {
        // base case
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + f_mem(dp, s1, i-1, s2, j-1);
        
        else return dp[i][j] = max(f_mem(dp, s1, i-1, s2, j) , f_mem(dp, s1, i, s2, j-1));
    }
    int f_SO(string &s1, string &s2, int m, int n) {
        
        vector<int> prev(n+1, 0); // for dp[i-1]
        vector<int> curr(n+1, 0); // for dp[i]
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
        
                else curr[j] = max(prev[j] , curr[j-1]);
    
            }
            prev = curr;
        }
        
        return prev[n];
    }
    int lcs(string &s1, string &s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        // return f(s1, m-1, s2, n-1);
        
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return f_mem(dp, s1, m-1, s2, n-1);
        
        return f_SO(s1, s2, m, n);
    } 
};
