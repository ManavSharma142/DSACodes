#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& arr) {

        sort(arr.begin(), arr.end());
        int resIdx = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[resIdx][1] >= arr[i][0])
                arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
            else {
                resIdx++;
                arr[resIdx] = arr[i];
            }
        }

        // Clean up unused part
        arr.erase(arr.begin() + resIdx + 1, arr.end());
        return arr;
    }
};