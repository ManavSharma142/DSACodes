#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long operations = 0;

        for(auto i : queries) {
            int l = i[0];
            int r = i[1];

            vector<int> temp;
            while(l <= r) {
                temp.push_back(l);
                l++;
            }

            int minIdx = 0, maxIdx = temp.size()-1;
            while(minIdx < temp.size() && maxIdx >= 0 && minIdx <= maxIdx) {
                while(minIdx < temp.size() && temp[minIdx] == 0) minIdx++;
                while(maxIdx >= 0 && temp[maxIdx] == 0) maxIdx--;
                
                if(minIdx < temp.size() && maxIdx >= 0) {
                    temp[minIdx] = temp[minIdx]/4;
                    temp[maxIdx] = temp[maxIdx]/4;
                    operations++;

                    sort(temp.begin(), temp.end());
                }
            }
        }

        return operations;
    }
};