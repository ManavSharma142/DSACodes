#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int> globalOrs;
        unordered_set<int> currOrs; // for possible ors of subarrays ending at idx-1

        for(auto i : arr) {
            unordered_set<int> nextOrs; // for possible ors of subarrays ending at current idx
            nextOrs.insert(i);
            for(auto j : currOrs) {
                nextOrs.insert(j | i);
            }

            // update curr
            currOrs = nextOrs;
            for(int val : currOrs) globalOrs.insert(val);
        }

        return globalOrs.size();

    }
};