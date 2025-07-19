#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> intToPos(int squareVal, int n) {
        int row = (squareVal - 1) / n;
        int col = (squareVal - 1) % n;
        // but if odd row 
        if(row % 2 != 0) col = n-col-1;

        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(), board.end());

        queue<pair<int, int>> q;
        unordered_map<int, bool> vis;
        vis[1] = true;
        q.push({1, 0});

        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();

            int squareVal = temp.first;
            int moves = temp.second;

            for(int i = 1; i < 7; i++) {
                int nxtSquare = squareVal + i;
                pair<int, int> pos = intToPos(nxtSquare, n);
                int r = pos.first;
                int c = pos.second;

                if(board[r][c] != -1) nxtSquare = board[r][c];
                if(nxtSquare == n*n) return moves+1;

                if(vis.find(nxtSquare) == vis.end()) {
                    vis[nxtSquare] = true;
                    q.push({nxtSquare, moves+1});
                }
            }
        }
        return -1;
    }
};