// User function Template for C++

class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // code here
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n+1, 0);
        
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        //push 0 indegree i q;
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        // do bfs

        vector<int> time(n+1, 1);
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            //update indegree
            for(auto i : adj[front]) {
                indegree[i]-- ;
                time[i] = max(time[i], time[front] + 1);
                if(indegree[i] == 0) q.push(i);
            } 
        }
        
        time.erase(time.begin());
        return time;
    }
};