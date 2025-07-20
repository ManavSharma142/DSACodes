#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].push_back({v, w});
        }

        queue<pair<pair<int, int>, int>> q;
        q.push({{src, 0}, 0});

        vector<int> minCost(n, INT_MAX);
        while(!q.empty()) {
            auto front = q.front(); q.pop();

            int node = front.first.first;
            int cost = front.first.second;
            int stops = front.second;

            if(stops > k) continue;

            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;

                if(cost + w < minCost[v]) {
                    minCost[v] = cost + w;
                    q.push({{v, minCost[v]}, stops+1});
                }
            }
        }
        
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};