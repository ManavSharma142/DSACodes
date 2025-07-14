#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int>& ans, unordered_map<int, bool>& vis, vector<vector<int>> &adj, int node ) {
        
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            vis[frontNode] = 1;
            ans.push_back(frontNode);
            
            for(auto i : adj[frontNode]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = 1;    
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> ans;
        unordered_map<int, bool> vis;
        bfs(ans, vis, adj, 0);
        return ans;
    }
};