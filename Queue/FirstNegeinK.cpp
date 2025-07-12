#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // process first window
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) q.push(i);
        }
        
        if(!q.empty()) ans.push_back(arr[q.front()]);
        else ans.push_back(0);
        
        //process further windows
        for(int i = k; i < arr.size(); i++) {
            //remove out of bounds elements
            while(!q.empty() && q.front() <= i-k) q.pop();
            
            if(arr[i] < 0) q.push(i);
            
            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};