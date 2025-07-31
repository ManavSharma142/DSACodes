#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // addSolution remains the same as your corrected version.
    void addSolution(vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string str = "";
            for(int j = 0; j < n; j++) {
                str += board[i][j];
            }
            temp.push_back(str); 
        }
        ans.push_back(temp);
    }

    // The old isSafe function is no longer needed and can be deleted.

    void solve(int col, vector<vector<string>>& ans, vector<vector<string>>& board, int n,
               vector<bool>& leftRow, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal) {

        // Base case: a solution is found
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // The O(1) safety check 🚀
            if (!leftRow[row] &&
                !lowerDiagonal[row + col] &&
                !upperDiagonal[col - row + n - 1]) {

                // Place the queen
                board[row][col] = "Q";
                leftRow[row] = true;
                lowerDiagonal[row + col] = true;
                upperDiagonal[col - row + n - 1] = true;

                // Recur for the next column
                solve(col + 1, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);

                // Backtrack: remove the queen and undo changes
                board[row][col] = ".";
                leftRow[row] = false;
                lowerDiagonal[row + col] = false;
                upperDiagonal[col - row + n - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;

        // Create the tracking vectors
        vector<bool> leftRow(n, false);
        vector<bool> upperDiagonal(2 * n - 1, false);
        vector<bool> lowerDiagonal(2 * n - 1, false);

        // Initial call to the recursive solver
        solve(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};