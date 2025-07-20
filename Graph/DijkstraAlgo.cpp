// User Function Template
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // set : distance - node
        set<pair<int, int>> s;
        vector<int> dis(V, INT_MAX);
        
        s.insert({0, src});
        dis[src] = 0;
        while(!s.empty()) {
            auto top = *(s.begin());
            int NodeDistance = top.first;
            int Node = top.second;
            
            s.erase(s.begin());
            
            for(auto i : adj[Node]) {
                if(NodeDistance + i.second < dis[i.first]) {
                    
                    auto record = s.find({dis[i.first], i.first});
                    
                    if(record != s.end()) s.erase(record);
                    
                    //update distance
                    dis[i.first] = NodeDistance + i.second;
                    s.insert({dis[i.first], i.first});
                }
            }
        }
        return dis;
        
    }
};

// Priority queue aproach

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build the adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // priority_queue: (distance, node), min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);
        
        dis[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int NodeDistance = top.first;
            int Node = top.second;
            
            // Skip if we already found a better path
            if(NodeDistance > dis[Node]) continue;
            
            for(auto i : adj[Node]) {
                int neighbor = i.first;
                int weight = i.second;
                
                if(NodeDistance + weight < dis[neighbor]) {
                    dis[neighbor] = NodeDistance + weight;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        
        return dis;
    }
};
