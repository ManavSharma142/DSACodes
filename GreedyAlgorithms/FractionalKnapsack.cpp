#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b) 
    {
        return a.first > b.first;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double, pair<int, int>>> PerUnit; //valperunit, Val, Wt  
        
        for(int i = 0; i < n; i++) {
            int itemVal = val[i];
            int itemWt = wt[i];
            
            double valPerUnit = (1.0 * itemVal) / itemWt;
            PerUnit.push_back({valPerUnit, {itemVal, itemWt}});
        }
        
        sort(PerUnit.begin(), PerUnit.end(), cmp);
        double totalVal = 0;
        for(int i = 0; i < n; i++) {
            if(PerUnit[i].second.second > capacity) {
                // i can take fractions only !
                totalVal += capacity*PerUnit[i].first;
                capacity = 0;
            }
            else{
                // i can take full values
                totalVal += PerUnit[i].second.first; 
                capacity -= PerUnit[i].second.second;
            }
        }
        
        return totalVal;
    }
};
