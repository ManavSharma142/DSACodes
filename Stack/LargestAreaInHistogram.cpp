#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:
    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n);
        ans[0] = -1;
        s.push(0);
        
        for(int i = 1; i < n; i++) {
            int ele = arr[i];
            while(!s.empty() && arr[s.top()] >= ele) s.pop();
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        vector<int> ans(n);
        ans[n - 1] = n;
        s.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--) {
            int curr = arr[i];
            while(!s.empty() && arr[s.top()] >= curr) s.pop();
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> next = nextSmallerElement(arr, n);
        vector<int> prev = prevSmallerElement(arr, n);
        
        int area = 0;
        for(int i = 0; i < n; i++) {
            int height = arr[i];
            int width = next[i] - prev[i] - 1;
            area = max(area, height * width);
        }
        return area;
    }
};
