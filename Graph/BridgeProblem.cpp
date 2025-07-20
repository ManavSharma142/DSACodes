#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, unordered_map<int, list<int>>& adj,
            vector<int>& low, vector<int>& disc, int parent,
            unordered_map<int, bool>& vis, bool& flag, int timer, int c, int d) {
                
                vis[node] = true;
                disc[node] = low[node] = timer++;
                
                for(auto i : adj[node]) {
                    if(i == parent) continue;
                    
                    if(!vis[i]) {
                        dfs(i, adj, low, disc, node, vis, flag, timer, c, d);
                        low[node] = min(low[node], low[i]);
                        
                        // check edge is bridge
                        if(low[i] > disc[node] && ((node == c && i == d) || (node == d && i == c))) {
                            flag = true;
                            return;
                        }
                    }
                    
                    else low[node] = min(low[node], disc[i]);
                }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        unordered_map<int, list<int>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> low(V, -1);
        vector<int> disc(V, -1);
        int parent = -1;
        unordered_map<int, bool> vis;
        bool flag = false;
        int timer = 0;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, adj, low, disc, parent, vis, flag, timer, c, d);
        }
        
        return flag;
    }
};