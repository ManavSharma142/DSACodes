#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++) parent[i] = i;

    }
    int findParent( int node) {
        if(parent[node] == node) return node;
        
        // path compression handled here too 
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] == rank[ulp_v]) {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++;
        }
        else {
            parent[ulp_v] = ulp_u;
        }
    } 
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }    
};

    


int main() {
    int V;
    vector<int> parent(V);
    for(int i = 0; i < V; i++) parent[i] = i;
        
    vector<int> rank(V, 0);
}