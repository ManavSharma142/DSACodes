#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long getSumInRange(int L, int R, vector<int>& positions, vector<long long>& prefixSum) {
        int n = positions.size();
        int startIdx = n;
        int s = 0;
        int e = n-1;
        //lowerBound
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(positions[mid] >= L) {
                startIdx = mid;
                e = mid-1;  // keep on looking for better answer
            }
            else s = mid+1;
        }

        //upperBound
        int endIdx = n;
        s = 0; 
        e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(positions[mid] > R) {
                endIdx = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        if(startIdx < endIdx) {
            return prefixSum[endIdx] - prefixSum[startIdx];
        }
        return 0;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        if(n==0) return 0;

        vector<int> positions;
        vector<long long> prefixSum(n+1, 0);

        for(int i = 0; i < n ; i++) {
            positions.push_back(fruits[i][0]);
            prefixSum[i+1] = prefixSum[i] + fruits[i][1]; 
        }

        long long maxFruit = 0;
        for(int x = 0 ; x <= k; x++) {
            // case 1 : left turn right
            int L1 = startPos - x;
            int R1 = startPos + k -2*x;
            maxFruit = max(maxFruit, getSumInRange(L1, R1, positions, prefixSum));

            // case 2 : right turn left
            int L2 = startPos + 2*x - k;
            int R2 = startPos + x;
            maxFruit = max(maxFruit, getSumInRange(L2, R2, positions, prefixSum));
        }

        return (int)maxFruit;
    }
    
    // sliding window appraoch
    int maxTotalFruits2(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int max_fruits = 0;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Expand the window to the right
            current_sum += fruits[right][1];

            // Cost calculation for the current window [left...right]
            int L = fruits[left][0];
            int R = fruits[right][0];
            
            // The cost is the distance to cover the range [L, R] plus the
            // distance from startPos to the nearest endpoint of that range.
            long long cost = (long long)(R - L) + min(abs(startPos - L), abs(startPos - R));

            // Shrink window from the left if it's too expensive
            while (cost > k) {
                current_sum -= fruits[left][1];
                left++;
                // Recalculate cost for the shrunken window
                L = fruits[left][0];
                cost = (long long)(R - L) + min(abs(startPos - L), abs(startPos - R));
            }

            // Update max_fruits with the current valid window's sum
            max_fruits = max(max_fruits, (int)(current_sum));
        }

        return max_fruits;
    }
};

