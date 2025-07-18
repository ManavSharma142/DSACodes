#include <bits/stdc++.h>
using namespace std;
// using bfs
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int, list<int>> adj;
        
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, bool> vis;
        queue<int> q;
        unordered_map<int, int> col;
        // using color as 1, 0
        
        q.push(0);
        vis[0] = true;
        col[0] = 0;
        
        while(!q.empty()) {
            int front = q.front();
            int nodeCol = col[front];
            q.pop();
            
            for(auto nbr : adj[front]) {
                if(!vis[nbr]) {
                    vis[nbr] = true;
                    if(nodeCol == 1) col[nbr] = 0;
                    else col[nbr] = 1;
                    q.push(nbr);
                }
                else{
                    if (col[nbr] == nodeCol) return false;
                }
            }
        }
        
        return true;
    }
};