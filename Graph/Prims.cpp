#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
    
        
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        
        key[0] = 0;
        
        for(int i = 0; i < V; i++) {
            int mini = INT_MAX;
            int u;
            // find min node
            for(int v = 0; v < V; v++) {
                if(mst[v] == false && key[v] < mini) {
                    u = v;
                    mini = key[v];
                }
            }
            
            // mark min node as true
            mst[u] = true;
            
            // check adj nodes
            for(auto i : adj[u]) {
                int v = i[0];
                int w = i[1];
                
                if(!mst[v] && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        
        int sum = 0;
        for(auto i : key) sum+=i;
        return sum;
    }
};