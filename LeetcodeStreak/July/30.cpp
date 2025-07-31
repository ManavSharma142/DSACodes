#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        for ( auto i : nums ) maxVal = max(maxVal, i);
        int maxLen=0;
        int i = 0;
        while(i<nums.size()) {
            if(nums[i] != maxVal) i++;
            int currLen =0;
            while( i < nums.size() && nums[i] == maxVal) {
                currLen++;
                i++;
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};