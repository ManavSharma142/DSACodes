#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        unordered_map<int, int> mp;
        int maxFruit = 0;
        for(int right = 0; right < n; right++) {
            mp[fruits[right]]++;
            while(mp.size() > 2) {
                int fruitToRemove = fruits[left];
                mp[fruitToRemove]--;
                if(mp[fruitToRemove] == 0) mp.erase(fruitToRemove);
                left++;
            }

            maxFruit = max(maxFruit, right - left + 1);
        }

        return maxFruit;
    }
};