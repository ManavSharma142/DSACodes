//Position this line where user code will be pasted.
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, unordered_map<int, bool>& vis, stack<int>& st) {
        
        vis[node] = 1;
        
        for(auto i : adj[node]) {
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        
        st.push(node);
    }
    void Revised_dfs(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj) {
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i]) Revised_dfs(i, vis, adj);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        unordered_map<int, bool> vis;
        stack<int> st;
        
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        
        // now trasnpose 
        unordered_map<int, list<int>> transpose;
        for(int i = 0;i < adj.size(); i++) {
            vis[i] = 0;
            for(auto nbr : adj[i]) {
                transpose[nbr].push_back(i);
            }
        }
        
        // dfs on rev graph
        int cnt = 0;
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(!vis[top]) {
                cnt++;
                Revised_dfs(top, vis, transpose);
            } 
        }
        
        return cnt;
    }
};