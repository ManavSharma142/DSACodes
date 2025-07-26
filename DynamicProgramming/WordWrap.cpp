// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(vector<int>& arr, int k, int i) {
        if(i == arr.size()) return 0;
        
        int currLen = 0;
        int minCost = INT_MAX;
        
        for(int j = i; j < arr.size(); j++) {
            currLen += arr[j];
            
            if(j > i) currLen++;
            
            if(currLen > k) break;
            
            int cost = (j == arr.size() - 1) ? 0 : (k - currLen) * (k - currLen);
            int totalCost = cost + solve(arr, k, j+1);
            minCost = min(totalCost, minCost);
        }
        return minCost;
    }
    int solveMem(vector<int>& arr, int k,int i, vector<int>& dp) {
        if(i == arr.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int currLen = 0;
        int minCost = INT_MAX;
        
        for(int j = i; j < arr.size(); j++) {
            currLen += arr[j];
            
            if(j > i) currLen++;
            
            if(currLen > k) break;
            
            int cost = (j == arr.size() - 1) ? 0 : (k - currLen) * (k - currLen);
            int totalCost = cost + solveMem(arr, k, j+1, dp);
            minCost = min(totalCost, minCost);
        }
        return dp[i] = minCost;
    }
    int solveTab(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1 , 0);
        
        for(int i = arr.size() - 1; i >= 0; i++) {
            int currLen = 0;
            int minCost = INT_MAX;
            
            for(int j = i; j < arr.size(); j++) {
                currLen += arr[j];
                
                if(j > i) currLen++;
                
                if(currLen > k) break;
                
                int cost = (j == arr.size() - 1) ? 0 : (k - currLen) * (k - currLen);
                int totalCost = cost + dp[j+1];
                minCost = min(totalCost, minCost);
            }
            dp[i] = minCost;
        }
        
        return dp[0];
        
    }
    int solveWordWrap(vector<int> arr, int k) {
        // Code here
        // return solve(arr, k, 0);
        // vector<int> dp(arr.size(), -1);
        // return solveMem(arr, k, 0, dp);
        
        return solveTab(arr, k);
    }
};