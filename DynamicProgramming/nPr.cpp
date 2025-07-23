// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
    #define MOD 1000000007
  public:
    int permutationCoeff(int n, int r) {
        // Code here
        if(r > n) return 0;
        
        long long res = 1;
        
        for(int i = 1; i <= r; i++) {
            res = ( (res % MOD) * (n-i+1)%MOD ) % MOD;
        }
        return (int)res;
        
    }
};
