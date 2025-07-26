#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(int row, int col, vector<vector<int>>& Keypad, int r, int c) {
        if(row >= 0 && row < r && col >= 0 && col < c && Keypad[row][col] != INT_MAX)
            return true;
        return false;
    }
    int f(int row, int col, int n, vector<vector<int>>& Keypad, int r, int c) {
        // base case
        if(n == 1) return 1;
        
        int count = 0;

        count +=  f(row, col, n-1, Keypad, r, c);
        if(isSafe(row-1, col, Keypad, r, c)) count +=  f(row-1, col, n-1, Keypad, r, c);
        if(isSafe(row+1, col, Keypad, r, c)) count +=  f(row+1, col, n-1, Keypad, r, c);
        if(isSafe(row, col-1, Keypad, r, c)) count += f(row, col-1, n-1, Keypad, r, c);
        if(isSafe(row, col+1, Keypad, r, c)) count +=  f(row, col+1, n-1, Keypad, r, c);
        
        return count;
    }
    int f_mem(vector<vector<vector<int>>>& dp, int row, int col, int n, vector<vector<int>>& Keypad, int r, int c) {
        // base case
        if(n == 1) return 1;
        
        
        if(dp[row][col][n] != -1) return dp[row][col][n]; 
        int count = 0;

        count +=  f_mem(dp, row, col, n-1, Keypad, r, c);
        if(isSafe(row-1, col, Keypad, r, c)) count +=  f_mem(dp, row-1, col, n-1, Keypad, r, c);
        if(isSafe(row+1, col, Keypad, r, c)) count +=  f_mem(dp, row+1, col, n-1, Keypad, r, c);
        if(isSafe(row, col-1, Keypad, r, c)) count +=  f_mem(dp, row, col-1, n-1, Keypad, r, c);
        if(isSafe(row, col+1, Keypad, r, c)) count +=  f_mem(dp, row, col+1, n-1, Keypad, r, c);
        
        return dp[row][col][n] = count;
    }
    int f_tab(int n) {

        int ans = 0;
        vector<vector<vector<int>>> 
        dp(n + 1, vector<vector<int>>(4, vector<int>(3, 0)));
    
        // Set dp[1][i][j] = 1
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                dp[1][i][j] = 1;
            }
        }
        dp[1][3][0] = 0;
        dp[1][3][2] = 0;
    
        vector<vector<int>> dir = 
        {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
    
                    // For cell * and #
                    if (i == 3 && (j == 0 || j == 2)) {
                        continue;
                    }
    
                    // Check for all 5 next cells
                    for (auto d : dir) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) {
                            dp[k][i][j] += dp[k - 1][x][y];
                        }
                    }
                }
            }
        }
    
        // Add ans from each cell
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans += dp[n][i][j];
            }
        }
    
        return ans;
}
    int getCount_SO(int n) {

        int ans = 0;
        vector<vector<int>> prev(4, vector<int>(3, 1));
        prev[3][0] = 0;
        prev[3][2] = 0;
    
        // matrix to store current states
        vector<vector<int>> curr(4, vector<int>(3));
    
        vector<vector<int>> dir = 
        {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    curr[i][j] = 0;
    
                    // For cell * and #
                    if (i == 3 && (j == 0 || j == 2)) {
                        continue;
                    }
    
                    // Check for all 5 next cells
                    for (auto d : dir) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) {
                            curr[i][j] += prev[x][y];
                        }
                    }
                }
            }
    
            // Update previous states
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    prev[i][j] = curr[i][j];
                }
            }
        }
    
        // Add ans from each cell
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans += prev[i][j];
            }
        }
    
        return ans;
    }


    int getCount(int n) {
        // code here
        vector<vector<int>> Keypad(4, vector<int>(3, 0));
        int Counter = 1;
        for(int row = 0; row < 4; row++) {
            for(int col = 0; col < 3; col++) {
                Keypad[row][col] = Counter++;
            }
        }
        
        Keypad[3][0] = INT_MAX;
        Keypad[3][1] = 0;
        Keypad[3][2] = INT_MAX;
        
        
        // // vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        // int ans = 0;
        // for(int row = 0; row < 4; row++) { 
        //     for(int col = 0; col < 3; col++) {
        //         if(Keypad[row][col] != INT_MAX) {
        //             int temp = f_mem(dp, row, col, n, Keypad, 4, 3);
        //             ans += temp;
        //         }
        //     }
        // }
        
        return f_tab(n);
        
        // return ans;
    }
};