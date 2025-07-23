#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    bool f(vector<int>& nums, int index, int target) {
        // base case
        if(target < 0) return false;
        if(target == 0) return true;
        if(index >= nums.size()) return false;

        bool incl = f(nums, index+1, target - nums[index]);
        bool excl = f(nums, index+1, target);

        return incl || excl;
    }
    bool f_mem(vector<vector<int>>& dp, vector<int>& nums, int index, int target) {
        // base case
        if(target < 0) return false;
        if(target == 0) return true;
        if(index >= nums.size()) return false;

        if(dp[index][target] != -1) return dp[index][target];

        bool incl = f_mem(dp, nums, index+1, target - nums[index]);
        bool excl = f_mem(dp, nums, index+1, target);

        return dp[index][target] = (incl || excl);
    }
    bool f_tab(vector<int>& nums, int Realtarget) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(Realtarget+1 , 0));

        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int index = n-1; index >= 0; index--) {
            for(int target = 0; target <= Realtarget; target++) {
                int incl = 0;
                if(target - nums[index] >= 0) incl = dp[index+1][target-nums[index]];
                int excl = dp[index+1][target];

                dp[index][target] = (incl || excl);
            }
        }
        return dp[0][Realtarget];
    }
    bool f_SO(vector<int>& nums, int Realtarget) {
        
        vector<int> curr(Realtarget+1, 0);
        vector<int> next(Realtarget+1, 0);
        int n = nums.size();
        
        for(int index = n-1; index >= 0; index--) {
            for(int target = 0; target <= Realtarget; target++) {
                curr[0] = 1;
                int incl = 0;
                if(target - nums[index] >= 0) incl = next[target-nums[index]];
                int excl = next[target];

                curr[target] = (incl || excl);
            }
            next = curr;
        }
        return next[Realtarget];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(auto i : nums) sum += i;

        if(sum & 1) return false;

        // return f(nums, 0, sum/2);

        // vector<vector<int>> dp(nums.size() + 1, vector<int> ((sum/2)+1 , -1));
        // return f_mem(dp, nums, 0, sum/2);

        // return f_tab(nums, sum/2);

        return f_SO(nums, sum/2);

    }
};