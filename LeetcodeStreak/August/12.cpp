#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
    
class Solution {
public:
    #define MOD 1000000007
    int solve(int currNum, long long maxLimit, int x, int n, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(currNum == maxLimit) return 0;
        
        if(dp[currNum][n] != -1) return dp[currNum][n];
        int incl = solve(currNum + 1, maxLimit, x, n - round(pow(currNum, x)), dp);
        int excl = solve(currNum + 1, maxLimit, x, n, dp);

        return dp[currNum][n] = (incl + excl ) % MOD;
        
    }
    int solve_tab(int x, int N, int maxLimit) {
        vector<vector<int>> dp(maxLimit+1, vector<int> (N+1, 0));

        for(int i = 0; i <= maxLimit; i++) {
            dp[i][0] = 1;
        }

        for(int currNum = maxLimit-1; currNum >= 1; currNum--) {
            for(int n = 0; n <= N; n++) {
                int incl = 0;
                if(n - round(pow(currNum, x)) >= 0) incl = dp[currNum + 1][n - round(pow(currNum, x))];
                int excl = dp[currNum + 1][n];

                dp[currNum][n] = (incl + excl ) % MOD;
            }
        }

        return dp[1][N];
    }
    int solve_SO(int x, int N, int maxLimit) {

        vector<int> curr(N+1, 0);
        vector<int> prev(N+1, 0);
        curr[0] = prev[0] = 1;

        for(int currNum = maxLimit-1; currNum >= 1; currNum--) {
            for(int n = 0; n <= N; n++) {
                int incl = 0;
                if(n - round(pow(currNum, x)) >= 0) incl = curr[n - round(pow(currNum, x))];
                int excl = curr[n];

                prev[n] = (incl + excl ) % MOD;
            }
            curr=prev;
        }

        return prev[N];
    }
    int numberOfWays(int n, int x) {
        long long maxLimit = n+1;
        for(int i = 1; i <= n; i++) {
            long long curr = pow(i, x);
            if(curr > n){
                maxLimit = i;
                break;
            } 
        }
        // vector<vector<int>> dp(maxLimit+1, vector<int> (n+1, -1));
        // int ans = solve(1, maxLimit, x, n, dp);
        // return ans;

        return solve_tab(x, n, maxLimit);
    }
};

// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// So basically this problem is a classic Decision Tree DP Problem, now why i am saying decision trees
// # Approach
// <!-- Describe your approach to solving the problem. --> 
// STEP 1 : 
// Suppose n given to us 10, and there us some x, let's ignore it for a while, now one thing is for sure that, whatever unique numbers we choose to build n, any of those numbers can never exceed the number n itself, For the example i gave i.e n = 10, even in the minimum case when x = 1, the maximum possible number that can form 10 is 10 only , because 10 to power 1 is 10 only, CONCLUSION : Any one of the unique numbers we will use to build n , can at max be n only ....

// STEP 2 : 
// Now that we have a search space , starting from 1 and ending at n, we can further reduce this search space from 1 to a integer say "maxLimit" 
// Now what is maxLimit ? 
// maxLimit is a number which raised to power x, is coming out to be greater than n, for example, n is 10, x is 2, it means if we choose 4, 4 to power 2 is 16 , which is greater than 10, so why spend time computing the numbers from 4 to 10? Therefore our new search space is from 1 to maxLimit which in this case will be 4, as we dont want to process this and numbers ahead of it

// STEP 3:
// Now comes the DP Decision Tree part, we will go all the way from 1 to maxLimit, AND, at every number , we have 2 choices, or 2 decisions to make, either we can include that number or exclude it, now what do i mean by including or excluding ? 
// if i am including , means i am using this number raised to power x to construct n, so we will subtract this currNum raised to power x from our n and pass this in a recursive call, as we want to check further, same applies for excluding, means we are not using this number, so keep n as it is in our recursive call ,just send next number
// # Complexity
// - Time complexity:
// <!-- Add your time complexity here, e.g. $$O(n)$$ -->

// - Space complexity:
// <!-- Add your space complexity here, e.g. $$O(n)$$ -->

// # Code
// ```cpp []

    
// class Solution {
// public:
//     #define MOD 1000000007
//     int solve(int currNum, long long maxLimit, int x, int n, vector<vector<int>>& dp) {
//         if(n == 0) return 1;
//         if(n < 0) return 0;
//         if(currNum == maxLimit) return 0;
        
//         if(dp[currNum][n] != -1) return dp[currNum][n];
//         int incl = solve(currNum + 1, maxLimit, x, n - round(pow(currNum, x)), dp);
//         int excl = solve(currNum + 1, maxLimit, x, n, dp);

//         return dp[currNum][n] = (incl + excl ) % MOD;
        
//     }
//     int solve_tab(int x, int N, int maxLimit) {

//         vector<int> curr(N+1, 0);
//         vector<int> prev(N+1, 0);
//         curr[0] = prev[0] = 1;

//         for(int currNum = maxLimit-1; currNum >= 1; currNum--) {
//             for(int n = 0; n <= N; n++) {
//                 int incl = 0;
//                 if(n - round(pow(currNum, x)) >= 0) incl = curr[n - round(pow(currNum, x))];
//                 int excl = curr[n];

//                 prev[n] = (incl + excl ) % MOD;
//             }
//             curr=prev;
//         }

//         return prev[N];
//     }
//     int numberOfWays(int n, int x) {    
//         long long maxLimit = n+1;
//         for(int i = 1; i <= n; i++) {
//             long long curr = pow(i, x);
//             if(curr > n){
//                 maxLimit = i;
//                 break;
//             } 
//         }
//         // vector<vector<int>> dp(maxLimit+1, vector<int> (n+1, -1));
//         // int ans = solve(1, maxLimit, x, n, dp);
//         // return ans;

//         return solve_tab(x, n, maxLimit);
//     }
// };
// ```