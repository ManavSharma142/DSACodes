#include<bits/stdc++.h>
using namespace std;
class Graph{
    public : 
    map<int, list<pair<int, int>>> adj;
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void printAdj() {
        for(auto i : adj) {
            cout << i.first << "-> " ;
            for(auto j : i.second) {
                cout << j.first << " : " << j.second <<" ";
            }cout << endl;
        }
    }

    void dfs(stack<int>& st, unordered_map<int, bool>& vis, int node) {
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i.first]) {
                dfs(st, vis, i.first);
            }
        }
        st.push(node);
        return ;
    }

    void getShortestPath(int src, vector<int>& dist, stack<int>& st) {

        dist[src] = 0;
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(dist[top] != INT_MAX) {
                for(auto i : adj[top]) {
                    if(dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    } 
                }
            }
        }
    }

};
int main() {
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4, 5, -2);
    int n = 6;
    // g.printAdj();
    stack<int> st;
    unordered_map<int, bool> vis;

    // topological sort
    for(int i = 0; i < n; i++) {
        if(!vis[i]) g.dfs(st, vis, i);
    }
    int src = 1;
    vector<int> dist(n, INT_MAX);
    g.getShortestPath(src, dist, st);

    cout << " Answer is " << endl;
    for(auto i : dist) cout << i << " ";
    cout << endl;
    return 0;

}

 