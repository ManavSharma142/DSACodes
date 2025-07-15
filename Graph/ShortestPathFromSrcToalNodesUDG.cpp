#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, -1); // distance initialized to -1 (unreachable)
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto neighbor : adj[front]) {
                if (dist[neighbor] == -1) { // not visited yet
                    dist[neighbor] = dist[front] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }
};
