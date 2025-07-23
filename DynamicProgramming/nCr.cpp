#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int fact(vector<int>& dp, int n) {
        
        // base case
        if(n==1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int res = n * fact(dp, n-1);
        return dp[n] = res;
    }
    int nCr(int n, int r) {
        // code here
        
        if(r > n) return 0;
        
        vector<int> dp(n+1, -1);
        
        int num = fact(dp, n);
        int den1 = fact(dp, r);
        int den2 = fact(dp, n-r);
        
        int res1 = num/den1;
        int res2 = res1/den2;
        
        return res2;
    }
    int nCr(int n, int r) {
        // code here
        if(r > n) return 0;
        
        long long res = 1;
        r = min(r, n-r);
        
        for(int i = 1; i <= r; i++) {
            res = res * (n-i+1);
            res = res/i;
        }
        
        return (int)res;
    }
};