#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(unordered_map<int, list<int>>& adj, vector<int>& state, stack<int>& st, int node) {
        state[node] = 1;
        for (auto i : adj[node]) {
            // 2nd case: if there is a cycle, return false
            if (state[i] == 1) return false;
            if (state[i] == 0) {
                if (!dfs(adj, state, st, i)) return false;
            }
        }
        state[node] = 2;
        st.push(node);
        return true;
    }

    vector<int> topoSort(vector<int>& present, unordered_map<int, list<int>>& adj) {
        vector<int> state(26, 0);
        stack<int> st;

        for (int i = 0; i < 26; i++) {
            if (present[i] && state[i] == 0) {
                if (!dfs(adj, state, st, i)) return {};
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_map<int, list<int>> adj;
        vector<int> present(26, 0); 

        for (auto &word : words)
            for (char c : word)
                present[c - 'a'] = 1;

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            
            // 1st case: if s1 is a prefix of s2 and s1 is longer than s2, return empty string
            if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2)
                return "";

            int len = min(s1.length(), s2.length());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(present, adj);
        if (topo.empty()) return "";

        string ans = "";
        for (int i : topo)
            ans += (char)(i + 'a');

        return ans;
    }
};
