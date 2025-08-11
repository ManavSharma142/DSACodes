#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     void f(vector<int>& nums, vector<bool>& vis, vector<int> p, vector<vector<int>>& res) {

//         if(p.size() == nums.size()) {
//             res.push_back(p);
//             return;
//         }
//         for(int j = 0; j < nums.size(); j++) {
//             if(vis[j]) continue;
//             if(j > 0 && nums[j] == nums[j-1] && !vis[j-1]) continue;

//             p.push_back(nums[j]);
//             vis[j] = true;
//             f(nums, vis, p, res);
//             vis[j] = false;
//             p.pop_back();
//         }
//     }
//     int buildNumber(vector<int>& temp) {
//         int res = 0;
//         int idx = 0;
//         for(int i = temp.size()-1; i >= 0; i--) {
//             res += temp[i] * pow(10, idx);
//             idx++;
//         }
//         return res;
//     }
//     bool reorderedPowerOf2(int n) {
//         // step 1 : prepare nums
//         vector<int> nums;
//         while(n!=0) {
//             int digit = n%10;
//             nums.push_back(digit);
//             n=n/10;
//         }
//         reverse(nums.begin(), nums.end());
//         sort(nums.begin(), nums.end());
//         //step2: find all permutations
//         vector<bool> vis(nums.size(), false);
//         vector<int> p;
//         vector<vector<int>> allPermutations;
//         f(nums, vis, p, allPermutations);

//         //step 3: get each permutation one by one, and check for power of 2
//         for(int i = 0 ; i < allPermutations.size(); i++) {
//             vector<int> temp = allPermutations[i];
//             if(temp[0] != 0) {
//                 int num = buildNumber(temp);
//                 if(num > 0 && !(num & num-1)) return true;
//             }
//         }
//         return false; 
//     }
// };



// best soln 
class Solution {
public:
    string numToStr(int x) {
        string str = to_string(x);
        sort(str.begin(), str.end());
        return str;
    }
    bool reorderedPowerOf2(int n) {
        string targetStr = numToStr(n);
        for(int i = 0 ; i < 30; i++) {
            string temp = numToStr(1 << i);
            if(temp == targetStr) return true;
        }
        return false;
    }
};