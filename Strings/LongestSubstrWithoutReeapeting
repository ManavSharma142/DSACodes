#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right < n; right++) {
            char curr = s[right];
            if(mp.count(curr) && mp[curr] >= left) {
                left = mp[curr] + 1;
            }
            mp[curr] = right;
            maxLen = max(maxLen, right - left + 1);   
        }

        return maxLen;
    }
};