#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define MOD 1000000007
    int power(int exp) {
        long long res = 1;
        long long base = 2;
        long long mod = 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return (int)res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> exponents;
        int position=0;
        while(n>0) {
            if(n%2!=0){
                exponents.push_back(position);
            }
            position++;
            n/=2;
        }

        vector<int> prefixSum(exponents.size());
        prefixSum[0] = exponents[0];
        for(int i = 1; i < exponents.size();i++) {
            prefixSum[i] = prefixSum[i-1] + exponents[i];
        }

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int totalExp = 0;
            if(left==0) totalExp = prefixSum[right];
            else totalExp = prefixSum[right] - prefixSum[left-1];

            ans[i] = (power(totalExp)) % MOD;
        }
        return ans;
    }
};