#include<bits/stdc++.h>
using namespace std;
// BF : O(n^2)
class Solution {
public:
    bool check(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2) {

        for(auto i: mp1) {
            int key = i.first;
            int val = i.second;
            // If the window has fewer characters than required, it's not a valid window.
            if (mp2.find(key) == mp2.end() || mp2[key] < val) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length(); 
        int size = INT_MAX;
        string ans = "";
        unordered_map<char, int> mp1;
        for(auto i : t) mp1[i]++;

        // A slightly better (but still too slow) approach
        for(int i = 0; i < m; i++) {
            unordered_map<char, int> mp2; // Create map once per starting position
            for(int j = i; j < m; j++) {
                mp2[s[j]]++; // Just add the new character's count
                
                if(check(mp1, mp2)) { // check if it's a valid window
                    if (j - i + 1 < size) {
                        size = j - i + 1;
                        ans = s.substr(i, size);
                    }
                }
            }
        }
        return ans;
    }
};
//space optmised soln , O(m+n)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto i : t) mp[i]++;

        int left = 0, right = 0;
        int minLen= 1e9;
        int cnt = 0;
        int sIdx = -1;
        while(right < s.length()) {
            
            //it means that char is preinserted , so means we found a pre-existing valid char!
            if(mp[s[right]] > 0) cnt++;
            mp[s[right]]--;

            // try to shrink window
            while(cnt == t.length()) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sIdx = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) cnt--;
                left++;
            }
            right++;
        }
        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};