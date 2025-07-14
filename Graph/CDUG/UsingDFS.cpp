#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool CycleDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis, int parent, int node ) {
        
        vis[node] = 1;
        
        for(auto i : adj[node]) {
            if(!vis[i]) {
                vis[i] = 1;
                bool temp = CycleDFS(adj, vis, node, i);
                if(temp) return true;
            }
            else if(i != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> vis;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bool flag = CycleDFS(adj, vis, -1,  i);
                if(flag) return true;
            }
        }
        return false;
    }
};