#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8; // or 1e9, but not INT_MAX to avoid overflow

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Cast to long long to avoid overflow
                    if (dist[i][via] < INF && dist[via][j] < INF) {
                        long long throughVia = 1LL * dist[i][via] + dist[via][j];
                        if (throughVia < dist[i][j]) {
                            dist[i][j] = (int)throughVia;
                        }
                    }
                }
            }
        }
    }
};
