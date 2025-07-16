// used to find articualtion point
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& disc, vector<int>& low,
        unordered_map<int, bool>& vis, int &timer, vector<int>& ap, int parent) { 

            vis[node] = true;
            disc[node] = low[node] = timer++;
            int child = 0;
            for(auto i : adj[node]) {
                if(i == parent) continue;
                
                if(!vis[i]) {
                    dfs(i, adj, disc, low,  vis, timer, ap, node);
                    low[node] = min(low[node], low[i]);
                    
                    // check ap of node
                    if(low[i] >= disc[node] && parent != -1) {
                        ap[node] = 1;     
                    }
                    child++;
                }
                else low[node] = min(low[node], disc[i]);
            }

            if(parent == -1 && child > 1) {
                ap[node] = 1;
            }   
}
int main() {
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    unordered_map<int, list<int>> adj;

    for(auto i : edges) {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, adj, disc, low, vis, timer, ap, -1);
    }

    //print ap

    cout << "Articulation points are as follows - > " << endl;
    for(int i = 0; i < n; i++) {
        if(ap[i] == 1) cout << i << " ";
    }


    return 0;
}