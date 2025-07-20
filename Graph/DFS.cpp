#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    void dfsUtil(vector<int>& ans, unordered_map<int, bool>& vis, vector<vector<int>>& adj, int node) {
        ans.push_back(node);
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i])
                dfsUtil(ans, vis, adj, i);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> vis;
        vector<int> ans;
        dfsUtil(ans, vis, adj, 0);
        return ans;
    }
};