#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if(parent[node] == node) return node;
        
        // path compression handled here too 
        return parent[node] = findParent(parent, parent[node]);
    }
    
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, parent[u]);
        v = findParent(parent, parent[v]);
        
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] == rank[v]) {
            parent[v] = u;
            rank[u]++;
        }
        else {
            parent[v] = u;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto i : connections) {
            unionSet(i[0], i[1], parent, rank);
        }

        int connectedComponents = 0;
        for(int i = 0; i < n; i++) {
            if(findParent(parent, i) == i) connectedComponents++;
        }

        return connectedComponents-1;
    }
};