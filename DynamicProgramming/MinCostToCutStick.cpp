#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>    
using namespace std;
class Solution {
public:
    int f(int i , int j , vector<int>& cuts) {
        if(i > j) return 0;

        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++) {
            int cost = cuts[j+1] - cuts[i-1] + f(i, idx-1, cuts) + f(idx+1, j, cuts);
            mini = min(cost, mini);
        }
        return mini;
    }
    int f_mem(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++) {
            int cost = cuts[j+1] - cuts[i-1] + f_mem(i, idx-1, cuts, dp) + f_mem(idx+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
    int f_tab(vector<int>& cuts, int c, int n) {

        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

        for(int i = c ; i >= 1; i--) {
            for(int j = 1; j <= c; j++) {
                if(i > j) continue;
                int mini = INT_MAX;

                for(int idx = i; idx <= j; idx++) {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = (mini);
            }
        }
        return dp[1][c];
    }
    int minCost(int n, vector<int>& cuts) {
        
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        // return f(1, c, cuts);

        // vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
        // return f_mem(1, c, cuts, dp);

        return f_tab(cuts, c, n);
    }
};