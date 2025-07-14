#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public: 
    unordered_map<int, list<int>> adj;

    // let direction 0 : undirected graph
    //     direction 1 : directed graph

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);

        if(!direction) adj[v].push_back(u);
    }

    void PrintAdj() {
        for(auto i : adj) {
            cout << i.first << "-> ";
            for(auto j : i.second) {
                cout << j << " ";
            }cout << endl;
        }
    }
};

int main() {
    Graph g; 
    // n is no of nodes, m is no of edged
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.PrintAdj();
    return 0;
}