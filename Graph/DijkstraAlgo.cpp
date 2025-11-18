// // User Function Template
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         // Code here
//         unordered_map<int, list<pair<int, int>>> adj;
//         for(auto i : edges) {
//             int u = i[0];
//             int v = i[1];
//             int w = i[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }
        
//         // set : distance - node
//         set<pair<int, int>> s;
//         vector<int> dis(V, INT_MAX);
        
//         s.insert({0, src});
//         dis[src] = 0;
//         while(!s.empty()) {
//             auto top = *(s.begin());
//             int NodeDistance = top.first;
//             int Node = top.second;
            
//             s.erase(s.begin());
            
//             for(auto i : adj[Node]) {
//                 if(NodeDistance + i.second < dis[i.first]) {
                    
//                     auto record = s.find({dis[i.first], i.first});
                    
//                     if(record != s.end()) s.erase(record);
                    
//                     //update distance
//                     dis[i.first] = NodeDistance + i.second;
//                     s.insert({dis[i.first], i.first});
//                 }
//             }
//         }
//         return dis;
        
//     }
// };

// Priority queue aproach

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // remove this if graph is directed
        }
        // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);
        dis[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int nodeDist = top.first;
            int node = top.second;

            // Skip outdated entries
            if (nodeDist > dis[node]) continue;

            for (auto i : adj[node]) {
                int neighbor = i.first;
                int weight = i.second;

                if (nodeDist + weight < dis[neighbor]) {
                    dis[neighbor] = nodeDist + weight;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }

        return dis;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    Solution obj;
    vector<int> dist = obj.dijkstra(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance: ";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}

