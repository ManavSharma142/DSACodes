#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        priority_queue<int> pq;
        unordered_map<char, int> track;
        
        for(auto i : s) track[i]++;
        
        for(auto i : track) pq.push(i.second);
        
        int c = 0;
        while(c < k) {
            int freq = pq.top();
            pq.pop();
            freq--;
            if(freq > 0) pq.push(freq);
            c++;
        }
        
        int sum = 0;
        while(!pq.empty()) {
            int temp = pq.top();
            pq.pop();
            sum += temp * temp;
        }
        
        return sum;
        
    }
};