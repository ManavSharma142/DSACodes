#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";
        for(auto i : s) {
            
            count[i]++;
            q.push(i);
            
            while(!q.empty()) {
                if(count[q.front()] > 1) q.pop();
                else {
                    ans.push_back(q.front());
                    break;
                } 
            }
            
            if(q.empty()) ans.push_back('#');
        }
        return ans;
    }
};