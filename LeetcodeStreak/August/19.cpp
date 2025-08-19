#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        long long zeroCounter = 0;
        for(int i = 0 ; i < n; i++) {
            if(nums[i] == 0) zeroCounter++;
            else{
                ans += ((1.0) * (zeroCounter + 1) / 2.0 ) * zeroCounter;
                zeroCounter = 0;
            }
        }

        if(zeroCounter != 0) ans += ((1.0) * (zeroCounter + 1) / 2.0 ) * zeroCounter;
        
        return ans;
    }
};