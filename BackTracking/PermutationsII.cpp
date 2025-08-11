#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(vector<int>& nums, unordered_map<int, int>& mp, vector<int> p, vector<vector<int>>& res) {

        if(p.size() == nums.size()) {
            res.push_back(p);
            return;
        }
        for(auto i : mp) {
            int num = i.first;
            if(mp[num] > 0) {
                p.push_back(num);
                mp[num]--;
                f(nums, mp, p, res);
                mp[num]++;
                p.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        vector<int> p;
        vector<vector<int>> res;
        f(nums, mp, p, res);
        return res;
    }

    // second approach
    void f2(vector<int>& nums, vector<bool>& vis, vector<int> p, vector<vector<int>>& res) {

        if(p.size() == nums.size()) {
            res.push_back(p);
            return;
        }
        for(int j = 0; j < nums.size(); j++) {
            if(vis[j]) continue;
            if(j > 0 && nums[j] == nums[j-1] && !vis[j-1]) continue;

            p.push_back(nums[j]);
            vis[j] = true;
            f2(nums, vis, p, res);
            vis[j] = false;
            p.pop_back();
        }
    }
    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> vis(nums.size(), false);
        vector<int> p;
        vector<vector<int>> res;
        f2(nums, vis, p, res);
        return res;
    }
};