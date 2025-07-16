
class Solution {
  public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
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
 
    int kruskalsMST(int V, vector<vector<int>> &edges) {

        // DisJointSet : 
        vector<int> parent(V);
        for(int i = 0; i < V; i++) parent[i] = i;
        
        vector<int> rank(V, 0);
        
        // start kruskals algo
        sort(edges.begin(), edges.end(), cmp);
        
        int minWeight = 0;
        
        for(int i = 0; i < edges.size(); i++) {
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            
            if(u != v) {
                minWeight += edges[i][2];
                unionSet(u, v, parent, rank);
            }
        }
        
        return minWeight;
        
    }
};