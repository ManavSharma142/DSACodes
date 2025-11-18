#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int i = 0; i < V; i++) {
            int mini = INT_MAX;
            int u = -1;

            // find minimum key vertex not yet included in MST
            for (int v = 0; v < V; v++) {
                if (!mst[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            mst[u] = true;

            // Update adjacent vertices
            for (auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                if (!mst[v] && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        int sum = 0;
        for (auto i : key) sum += i;
        return sum;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Since the graph is undirected, add both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Solution obj;
    int ans = obj.spanningTree(V, adj);
    cout << "Sum of weights of MST: " << ans << endl;

    return 0;
}
