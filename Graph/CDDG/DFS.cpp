#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(unordered_map<int, list<int>>& adj,
    unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVis, 
    int node)
    {
        visited[node] = 1;
        dfsVis[node] = 1;
        for(auto i : adj[node]) {
            if(!visited[i]) {
                bool check = dfs(adj, visited, dfsVis, i);
                if(check) return true;
            }
            else if(dfsVis[i]) {
                return true;
            }
        }
        // backtrack
        dfsVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVis;
        for(int i = 0 ; i < V; i++) {
            if(!visited[i]) {
                bool ans = dfs(adj, visited, dfsVis, i);
                if(ans) return true;
            }
        }
        
        return false;
    }
};