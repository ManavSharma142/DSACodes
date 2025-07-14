#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(unordered_map<int, list<int>>& adj,
    unordered_map<int, bool>& visited,stack<int>& st, 
    int node)
    {
        visited[node] = 1;

        for(auto i : adj[node]) {
            if(!visited[i]) dfs(adj, visited,st, i);
        }
        // backtrack
        st.push(node);
        return ;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int, bool> visited;
        stack<int> st;
        for(int i = 0 ; i < V; i++) {
            if(!visited[i]) {
                dfs(adj, visited, st, i);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};