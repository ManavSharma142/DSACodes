#include<bits/stdc++.h>
using namespace std;

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

int main() {
    int V;
    vector<int> parent(V);
    for(int i = 0; i < V; i++) parent[i] = i;
        
    vector<int> rank(V, 0);
}