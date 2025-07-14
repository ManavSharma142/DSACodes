#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    void dfs(vector<int>& ans, unordered_map<int, bool>& vis, vector<vector<int>>& adj, int node) {
        ans.push_back(node);
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i])
                dfs(ans, vis, adj, i);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> vis;
        vector<int> ans;
        dfs(ans, vis, adj, 0);
        return ans;
    }
};