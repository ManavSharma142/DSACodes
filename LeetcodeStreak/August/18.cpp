#include<bits/stdc++.h>
using namespace std;
bool isValid_Util(double a, double b, double c) {
    if(isValid_Util2(a+b, c) || isValid_Util2(a-b, c) || isValid_Util2(a*b, c) || 
    (b && isValid_Util2(a/b, c))) return true;

    if(isValid_Util2(a,b+c) || isValid_Util2(a,b-c) || isValid_Util2(a, b*c) ||
      (c && isValid_Util2(a, b/c))) return true;

    return false;
}
bool isValid_Util2(double a, double b) {
    if(abs(a+b-24) <= 1e-5 || abs(a-b-24) <= 1e-5 || abs(a*b-24) <= 1e-5 || abs(a/b-24) <= 1e-5) return true;

    return false;
}
bool isValid(vector<int>& cards) {
    double a = cards[0];
    double b = cards[1];
    double c = cards[2];
    double d = cards[3];

    if(isValid_Util(a+b, c, d) || isValid_Util(a-b, c, d) || isValid_Util(a*b, c, d) || isValid_Util(a/b, c, d)) return true;

    if(isValid_Util(a,b+c, d) || isValid_Util(a,b-c, d) || isValid_Util(a, b*c, d) || isValid_Util(a, b/c, d)) return true;

    if(isValid_Util(a,b, c+d) || isValid_Util(a, b, c-d) || isValid_Util(a, b, c*d) || isValid_Util(a, b, c/d)) return true;

    return false;
}
bool judgePoint24(vector<int>& cards) {
    
    sort(cards.begin(), cards.end());
    if(isValid(cards)) return true;
    while(next_permutation(cards.begin(), cards.end())) {
        if(isValid(cards)) return true;
    }
    return false;
}