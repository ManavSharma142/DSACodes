#include<vector>
#include<limits.h>
using namespace std;
class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        
        vector<int> dist(n, INT_MAX);
        int m = edges.size();
        for(int src = 0; src < n; src++) {
            if(dist[src] != INT_MAX) continue; // already relaxed via previous run

            dist[src] = 0;

            
            for(int i = 0; i < n - 1; i++) {
                for(int j = 0; j < m; j++) {
                    int u = edges[j][0];
                    int v = edges[j][1];
                    int w = edges[j][2];

                    if(dist[u] != INT_MAX && (dist[u] + w < dist[v])) 
                        dist[v] = dist[u] + w;
                }    
            }

            // check for negative cycle
            for(int i = 0; i < m; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                if(dist[u] != INT_MAX && (dist[u] + w < dist[v])) 
                    return 1;
            }
        }
        
        return 0;
    }
};
