#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            // Store result after the first k-1 elements
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }

        return ans;
    }
};
