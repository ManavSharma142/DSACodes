#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        // code here
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        
        for(auto i : prerequisites) {
            int v = i[0];
            int u = i[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        //push 0 indegree i q;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        // do bfs

        vector<int> ans;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            //update indegree
            for(auto i : adj[front]) {
                indegree[i]-- ;
                if(indegree[i] == 0) q.push(i);
            } 
        }
        if(ans.size() == n) return ans;
        else return {};
    }
};