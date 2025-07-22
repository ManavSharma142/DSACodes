#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:   
    int f(int W, vector<int> &val, vector<int> &wt, int index, int n) {
        
        // base case
        if(index == n-1) {
            if(wt[n-1] <= W)
                return val[n-1];
            return 0;
        }
        
        int incl  = 0;
        if(wt[index] <= W)
            incl = val[index] + f(W-wt[index], val, wt, index+1, n); 
        
        int excl = f(W, val, wt, index+1, n);
        
        return max(incl, excl);
    }
    int solveTab(vector<int>& weight, vector<int>& value, int n, int W){
        //create dp array
        vector<vector<int> > dp(n, vector<int>(W+1, 0));
        //analyse base case
        for( int w = weight[0]; w<=W; w++ ){
            if(weight[0] <= W){
                dp[0][w] = value[0];
            }
            else{
                dp[0][w] = 0;
            }
        }
        for( int index =1; index<n ;index++){
            for(int w=0;w<=W;w++){
                int incl = 0;
                if(weight[index] <= w){
                    incl = value[index] + dp[index-1][w-weight[index]];
                }
                int excl = dp[index-1][w];
                dp[index][w] = max(incl, excl);
            }
        }
        return dp[n-1][W];       
    }
    int solveOpt(vector<int>& weight, vector<int>& value, int n, int W){
        //create dp array
        vector<int> prev(W+1);
        vector<int> curr(W+1);
        //analyse base case
        for( int w = weight[0]; w<=W; w++ ){
            if(weight[0] <= W){
                prev[w] = value[0];
            }
            else{
                prev[w] = 0;
            }
        }
        for( int index =1; index<n ;index++){
            for(int w=0;w<=W;w++){
                int incl = 0;
                if(weight[index] <= w){
                    incl = value[index] + prev[w-weight[index]];
                }
                int excl = prev[w];
                curr[w] = max(incl, excl);
            }
            prev = curr;
        }
        return prev[W];       
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int index = 0;
        int n = val.size();
        // int res = f(W, val, wt, index, n);
        
        // vector<vector<int>> dp(W+1, vector<int> (n+1, -1));
        // int res = f_mem(dp, W, val, wt, index, n);
        // return res;
        
        
        // return solveTab(wt, val, n, W);
        
        return solveOpt(wt, val, n, W);
    }
};