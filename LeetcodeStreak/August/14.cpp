#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        string ans = "";
        while(right < n) {
            while(s[left] == s[right] && right - left + 1 < 3) right++;

            if(right-left+1 == 3 && s[left] == s[right]) {
                if(s.substr(left, 3) > ans) ans = s.substr(left, 3);
            }
            left++; 
        }
        return ans;
    }
};