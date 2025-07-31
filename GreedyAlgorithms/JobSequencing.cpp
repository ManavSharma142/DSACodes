#include<bits/stdc++.h>
using namespace std;
// Greeedy Soln (TLE)
class Solution {
  public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({deadline[i], profit[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int maxProfit = 0, cnt = 0, maxDeadline = -1;
        for(auto i : deadline) maxDeadline = max(maxDeadline, i);
        vector<bool> hash(maxDeadline+1, false);
        
        for(int i = 0; i < n; i++) {
            for(int j = v[i].first; j > 0; j--) {
                if(!hash[j]) {
                    cnt++;
                    maxProfit += v[i].second;
                    hash[j] = true;
                    break;
                }
            }
        }
       return {cnt, maxProfit};
    }
};

// Disjoint Solution
class DSU{
    public:
    vector<int> parent;
    DSU(int d) {
        parent.resize(d+1);
        for(int i = 0 ; i <= d; i++) {
            parent[i] = i;
        }
    }
    int find(int s) {
        if(s == parent[s]) return s;
        
        return parent[s] = find(parent[s]);
    }
    void merge(int u, int v){

        //update the greatest available
        //free slot to u
        parent[v] = u;
    }
    
};
class Solution {
  public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({deadline[i], profit[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int maxProfit = 0, cnt = 0, maxDeadline = -1;
        for(auto i : deadline) maxDeadline = max(maxDeadline, i);
        
        DSU ds = DSU(maxDeadline);
        
        for(int i = 0; i < n; i++) {
            
            int slots = ds.find(v[i].first);
            if(slots > 0) {
                
                ds.merge(ds.find(slots - 1), slots);
            
                // update answer
                maxProfit += v[i].second;
                cnt++;
            }
            
        }
       return {cnt, maxProfit};
    }
};