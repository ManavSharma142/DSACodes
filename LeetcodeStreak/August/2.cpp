#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp;
        long long count = 0;
        for(int i = 0; i<basket1.size(); i++)
        {
            mp[basket1[i]]++;
            mp[basket2[i]]--;
        }

        int smallest = begin(mp)->first;
        vector<int> swaps;
        for(auto i : mp)
        {
            int a = i.first;
            int b = i.second;
            if(b%2)
                return -1;
            for(int i = 0; i<abs(b)/2; i++)
                swaps.push_back(a);
        }

        long long mini = 0;
        for(int i = 0; i<(swaps.size()/2); i++)
        {
            mini += min(swaps[i], 2*smallest);
        }

        return mini;

        
    }
};