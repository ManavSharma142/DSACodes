#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;

    // Check same row (left side)
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // Check upper diagonal (left-up)
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // Check lower diagonal (left-down)
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = nQueen(n);
    cout << "Number of solutions: " << res.size() << endl;
    return 0;
}
