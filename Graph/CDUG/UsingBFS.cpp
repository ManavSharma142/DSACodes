#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool CycleBFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int,int>& parent, int node ) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        parent[node] = -1;
        
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            for(auto i : adj[frontNode]) {
                if(vis[i] && i != parent[frontNode]) return true;
                else if(!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                    parent[i] = frontNode;
                }
            }
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
        unordered_map<int,int> parent;
        unordered_map<int, bool> vis;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bool flag = CycleBFS(adj, vis, parent,  i);
                if(flag) return true;
            }
        }
        return false;
    }
};