#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        for(auto i : nums) if(i == 1) oneCount++;

        if(oneCount == n) return n-1;

        int ans = 0;
        int i = 0;
        while(i < n) {
            if(nums[i] == 0) {
                int left = i, right = i;
                // expand left side
                while(left-1 >= 0 && nums[left-1] == 1) left--;
                // expand right side
                while(right+1 < n && nums[right+1] == 1) right++;

                ans = max(ans, right - left);
                i = right + 1;
            }
            else i++;
        }

        return ans;
    }
};