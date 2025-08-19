#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double f(int& n, int& k , int& maxPts, int currPts, vector<double>& dp) {
        if(currPts >= k) {
            if(currPts <= n){ 
                return 1.0;
            } 
            return 0.0;
        }
        if(dp[currPts] != -1.0) return dp[currPts];

        double nextOutcomeProb = 0.0;
        for(int i = 1; i <= maxPts; i++) {
            nextOutcomeProb += f(n, k, maxPts, currPts + i, dp);
        }
        return dp[currPts] = nextOutcomeProb/maxPts;
    }
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k+maxPts+1, -1.0);
        return f(n, k, maxPts, 0, dp);
    }
};


// Optmised Solution 
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts <= n) return 1.0;

        // we are first calculating the first window's sum as we know the window's elements values will be either 1 or 0 based on these 2 conditions 
        double windowSum = 0.0;
        for(int i = k; i < k + maxPts; i++) {
            if(i <= n) windowSum += 1;
            else windowSum += 0;
        }

        vector<double> dp(n+1);
        for(int i = k-1; i >= 0; i--) {

            dp[i] = windowSum/maxPts;

            //update window sum, remove value from rightmost end, i.e i + maxPts, and add value of left side i.e curr probability
            double removeValue = 0.0;
            if(i + maxPts <= n) {
                if (i + maxPts >= k) {
                    removeValue = 1.0; 
                } else {
                    removeValue = dp[i + maxPts];
                }
            }
            windowSum += dp[i] - removeValue;
            
        }
        return dp[0];
    }
};