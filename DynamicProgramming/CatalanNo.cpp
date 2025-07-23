#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the nth catalan number.
    long long nCr(int n, int r) {
        // code here
        if(r > n) return 0;
        
        long long res = 1;
        r = min(r, n-r);
        
        for(int i = 1; i <= r; i++) {
            res = res * (n-i+1);
            res = res/i;
        }
        
        return res;
    }
    int findCatalan(int n) {
        // code here
        return int(nCr(2*n, n) / (n+1));
    }
};