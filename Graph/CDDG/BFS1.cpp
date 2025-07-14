#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        int cnt = 0;
        unordered_map<int, list<int>> adj;
        for(auto i : edges) {
            int u = i[0] ;
            int v = i[1] ;
            
            adj[u].push_back(v);
        }
        
        // find all indegrees
        vector<int> indegree(V);
        for(auto i : adj) {
            for(auto j : i.second) {
                indegree[j]++;
            }
        }
        
        //push 0 indegree i q;
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        // do bfs
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cnt++;
            //update indegree
            for(auto i : adj[front]) {
                indegree[i]-- ;
                if(indegree[i] == 0) q.push(i);
            } 
        }
        return !(cnt == V);
    }
};
